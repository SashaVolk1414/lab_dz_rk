#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <pqxx/pqxx>

using namespace std;

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 a = T1(), T2 b = T2()) : first(a), second(b) {}

    void display() const {
        cout << first << " -> " << second << endl;
    }
};

template<typename T>
class Logger {
private:
    ofstream logFile;

public:
    Logger(const string& filename = "log.txt") {
        logFile.open(filename, ios::app);
    }

    ~Logger() {
        if (logFile.is_open()) logFile.close();
    }

    void log(const T& message) {
        if (logFile.is_open()) {
            logFile << message << endl;
        }
        cout << "[LOG] " << message << endl;
    }
};

class Product {
public:
    int id;
    string name;
    double price;

    Product(int id = 0, string name = "", double price = 0.0)
        : id(id), name(name), price(price) {
    }

    virtual void display() const {
        cout << "[" << id << "] " << name << " - $" << price;
    }

    virtual string getType() const { return "Product"; }
    virtual ~Product() {}
};

class DigitalProduct : public Product {
public:
    string license;

    DigitalProduct(int id = 0, string name = "", double price = 0.0, string license = "")
        : Product(id, name, price), license(license) {
    }

    void display() const override {
        Product::display();
        cout << " [Digital]" << endl;
    }

    string getType() const override { return "DigitalProduct"; }
};

class PhysicalProduct : public Product {
public:
    double weight;

    PhysicalProduct(int id = 0, string name = "", double price = 0.0, double weight = 0.0)
        : Product(id, name, price), weight(weight) {
    }

    void display() const override {
        Product::display();
        cout << " [Physical, " << weight << "kg]" << endl;
    }

    string getType() const override { return "PhysicalProduct"; }
};



class SalesSystem {
private:
    pqxx::connection conn;
    Logger<string> logger;

    void executeSQL(const string& sql) {
        try {
            pqxx::work txn(conn);
            txn.exec(sql);
            txn.commit();
        }
        catch (const exception& e) {
            logger.log("SQL Error: " + string(e.what()));
        }
    }

public:
    SalesSystem(const string& dbname, const string& user, const string& password)
        : conn("dbname=" + dbname + " user=" + user + " password=" + password) {

        if (conn.is_open()) {
            logger.log("Connected to database");
            initializeDB();
        }
    }

    void initializeDB() {
        // Создание таблиц
        string sql =
            "CREATE TABLE IF NOT EXISTS products ("
            "id SERIAL PRIMARY KEY, name TEXT, price REAL);"

            "CREATE TABLE IF NOT EXISTS orders ("
            "order_id SERIAL PRIMARY KEY, order_date DATE DEFAULT CURRENT_DATE);"

            "CREATE TABLE IF NOT EXISTS order_items ("
            "item_id SERIAL PRIMARY KEY, order_id INTEGER, product_id INTEGER, "
            "quantity INTEGER, total_price REAL);"

            "CREATE INDEX IF NOT EXISTS idx_date ON orders(order_date);"
            "CREATE INDEX IF NOT EXISTS idx_product ON order_items(product_id);";

        executeSQL(sql);
        logger.log("Database initialized");
    }



    void addProduct(const string& name, double price) {
        string sql = "INSERT INTO products (name, price) VALUES ('" + name + "', " + to_string(price) + ")";
        executeSQL(sql);
        logger.log("Added product: " + name);
    }

    void addOrder() {
        executeSQL("INSERT INTO orders DEFAULT VALUES");
        logger.log("Added new order");
    }

    void addOrderItem(int order_id, int product_id, int quantity) {
        try {
            pqxx::work txn(conn);
            auto res = txn.exec("SELECT price FROM products WHERE id = " + to_string(product_id));

            if (!res.empty()) {
                double price = res[0][0].as<double>();
                double total = price * quantity;

                string sql = "INSERT INTO order_items (order_id, product_id, quantity, total_price) VALUES (" +
                    to_string(order_id) + ", " + to_string(product_id) + ", " +
                    to_string(quantity) + ", " + to_string(total) + ")";
                txn.exec(sql);
                txn.commit();
                logger.log("Added order item");
            }
        }
        catch (const exception& e) {
            logger.log("Error: " + string(e.what()));
        }
    }


    void showProducts() {
        try {
            pqxx::work txn(conn);
            auto res = txn.exec("SELECT * FROM products");

            cout << "\n=== PRODUCTS ===" << endl;
            for (auto row : res) {
                cout << row["id"].as<int>() << ". "
                    << row["name"].c_str() << " - $"
                    << row["price"].as<double>() << endl;
            }
        }
        catch (const exception& e) {
            logger.log("Error: " + string(e.what()));
        }
    }

    void showOrders() {
        try {
            pqxx::work txn(conn);
            auto res = txn.exec("SELECT * FROM orders");

            cout << "\n=== ORDERS ===" << endl;
            for (auto row : res) {
                cout << "Order #" << row["order_id"].as<int>()
                    << " - " << row["order_date"].as<string>() << endl;
            }
        }
        catch (const exception& e) {
            logger.log("Error: " + string(e.what()));
        }
    }

    void revenueReport() {
        try {
            pqxx::work txn(conn);
            auto res = txn.exec(
                "SELECT p.name, SUM(oi.total_price) as revenue "
                "FROM products p JOIN order_items oi ON p.id = oi.product_id "
                "GROUP BY p.name ORDER BY revenue DESC"
            );

            cout << "\n=== REVENUE REPORT ===" << endl;
            for (auto row : res) {
                cout << row["name"].c_str() << ": $"
                    << row["revenue"].as<double>() << endl;
            }
        }
        catch (const exception& e) {
            logger.log("Error: " + string(e.what()));
        }
    }

    void topProducts() {
        try {
            pqxx::work txn(conn);
            auto res = txn.exec(
                "SELECT p.name, SUM(oi.quantity) as sold "
                "FROM products p JOIN order_items oi ON p.id = oi.product_id "
                "GROUP BY p.name ORDER BY sold DESC LIMIT 3"
            );

            cout << "\n=== TOP 3 PRODUCTS ===" << endl;
            int i = 1;
            for (auto row : res) {
                cout << i++ << ". " << row["name"].c_str()
                    << " (" << row["sold"].as<int>() << " sold)" << endl;
            }
        }
        catch (const exception& e) {
            logger.log("Error: " + string(e.what()));
        }
    }

    void avgOrderValue() {
        try {
            pqxx::work txn(conn);
            auto res = txn.exec(
                "SELECT AVG(total) as avg FROM ("
                "SELECT SUM(total_price) as total FROM order_items GROUP BY order_id"
                ") as totals"
            );

            cout << "\n=== AVERAGE ORDER VALUE ===" << endl;
            cout << "$" << res[0]["avg"].as<double>() << endl;
        }
        catch (const exception& e) {
            logger.log("Error: " + string(e.what()));
        }
    }

    void ordersPerProduct() {
        try {
            pqxx::work txn(conn);
            auto res = txn.exec(
                "SELECT p.name, COUNT(DISTINCT oi.order_id) as orders "
                "FROM products p LEFT JOIN order_items oi ON p.id = oi.product_id "
                "GROUP BY p.name"
            );

            cout << "\n=== ORDERS PER PRODUCT ===" << endl;
            for (auto row : res) {
                cout << row["name"].c_str() << ": "
                    << row["orders"].as<int>() << " orders" << endl;
            }
        }
        catch (const exception& e) {
            logger.log("Error: " + string(e.what()));
        }
    }


    void demoPolymorphism() {
        cout << "\n=== POLYMORPHISM DEMO ===" << endl;

        vector<Product*> products;
        products.push_back(new DigitalProduct(1, "Windows 10", 199.99, "ABC123"));
        products.push_back(new PhysicalProduct(2, "Laptop", 999.99, 2.5));
        products.push_back(new DigitalProduct(3, "Photoshop", 249.99, "XYZ789"));

        for (auto p : products) {
            p->display();
            delete p;
        }
        products.clear();
    }

    void demoPairTemplate() {
        cout << "\n=== PAIR TEMPLATE DEMO ===" << endl;

        Pair<string, int> productSales("Laptop", 50);
        Pair<string, double> productRevenue("Mouse", 1250.75);
        Pair<int, string> orderInfo(1001, "Completed");

        cout << "Product Sales: "; productSales.display();
        cout << "Product Revenue: "; productRevenue.display();
        cout << "Order Info: "; orderInfo.display();
    }
};

void showMenu() {
    cout << "\n=== SALES MANAGEMENT SYSTEM ===" << endl;
    cout << "1. Add Product" << endl;
    cout << "2. Add Order" << endl;
    cout << "3. Add Order Item" << endl;
    cout << "4. Show Products" << endl;
    cout << "5. Show Orders" << endl;
    cout << "6. Revenue Report" << endl;
    cout << "7. Top 3 Products" << endl;
    cout << "8. Average Order Value" << endl;
    cout << "9. Orders Per Product" << endl;
    cout << "10. Demo Polymorphism" << endl;
    cout << "11. Demo Pair Template" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: ";
}



int main() {
    string dbname = "sales_db";
    string user = "postgres";
    string password = "1234";

    try {
        SalesSystem system(dbname, user, password);

        int choice;
        do {
            showMenu();
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                double price;
                cout << "Product name: ";
                cin >> name;
                cout << "Price: ";
                cin >> price;
                system.addProduct(name, price);
                break;
            }
            case 2:
                system.addOrder();
                break;
            case 3: {
                int oid, pid, qty;
                cout << "Order ID: ";
                cin >> oid;
                cout << "Product ID: ";
                cin >> pid;
                cout << "Quantity: ";
                cin >> qty;
                system.addOrderItem(oid, pid, qty);
                break;
            }
            case 4:
                system.showProducts();
                break;
            case 5:
                system.showOrders();
                break;
            case 6:
                system.revenueReport();
                break;
            case 7:
                system.topProducts();
                break;
            case 8:
                system.avgOrderValue();
            break; case 9:
                system.ordersPerProduct();
                break;
            case 10:
                system.demoPolymorphism();
                break;
            case 11:
                system.demoPairTemplate();
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
            }
        } while (choice != 0);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <functional>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <locale.h>
#include <pqxx/pqxx>
using namespace std;

template<typename T>
class DatabaseConnection {
private:
    unique_ptr<pqxx::connection> conn;
    unique_ptr<pqxx::work> transaction;

public:
    explicit DatabaseConnection(const  string& connection_string) {
        try {
            conn = make_unique<pqxx::connection>(connection_string);
            if (!conn->is_open()) {
                throw  runtime_error("Failed to connect to database");
            }
            cout << "Database connection established: " << conn->dbname() << endl;
        }
        catch (const  exception& e) {
            cerr << "Connection error: " << e.what() << endl;
            throw;
        }
    }
    //SELECT
    vector< vector< string>> executeQuery(const  string& query) {
        vector< vector< string>> results;
        try {
            pqxx::work txn(*conn);
            pqxx::result res = txn.exec(query);
            txn.commit();

            for (const auto& row : res) {
                vector< string> row_data;
                for (const auto& field : row) {
                    row_data.push_back(field.is_null() ? "" : field.c_str());
                }
                results.push_back(row_data);
            }
        }
        catch (const  exception& e) {
            cerr << "Query execution error: " << e.what() << endl;
            throw;
        }
        return results;
    }

    //  INSERT, UPDATE, DELETE
    void executeNonQuery(const  string& query) {
        try {
            pqxx::work txn(*conn);
            txn.exec(query);
            txn.commit();
        }
        catch (const  exception& e) {
            cerr << "Command execution error: " << e.what() << endl;
            throw;
        }
    }

    // Start transaction
    void beginTransaction() {
        transaction = make_unique<pqxx::work>(*conn);
    }

    // Complete transaction
    void commitTransaction() {
        if (transaction) {
            transaction->commit();
            transaction.reset();
        }
    }

    // Rollback transaction
    void rollbackTransaction() {
        if (transaction) {
            transaction->abort();
            transaction.reset();
        }
    }

    // Execute query within current transaction
    pqxx::result executeInTransaction(const  string& query) {
        if (!transaction) {
            throw  runtime_error("Transaction not started");
        }
        return transaction->exec(query);
    }

    // Create function in PostgreSQL
    void createFunction(const  string& function_sql) {
        executeNonQuery(function_sql);
    }

    // Create trigger in PostgreSQL
    void createTrigger(const  string& trigger_sql) {
        executeNonQuery(trigger_sql);
    }

    // Check transaction status
    string getTransactionStatus() {
        if (transaction) {
            return "Transaction active";
        }
        return "No active transaction";
    }

    ~DatabaseConnection() {
        if (transaction) {
            transaction->abort();
        }
        if (conn && conn->is_open()) {
            conn->close();
            cout << "Database connection closed" << endl;
        }
    }
};


class PaymentStrategy {
public:
    virtual ~PaymentStrategy() = default;
    virtual bool pay(double amount) = 0;
    virtual  string getPaymentMethod() const = 0;
};

class CardPayment : public PaymentStrategy {
public:
    bool pay(double amount) override {
        cout << "Payment by bank card for amount: " << amount << " rub." << endl;
        return true;
    }

    string getPaymentMethod() const override {
        return "Bank card";
    }
};

class EWalletPayment : public PaymentStrategy {
public:
    bool pay(double amount) override {
        cout << "Payment via electronic wallet for amount: " << amount << " rub." << endl;
        return true;
    }

    string getPaymentMethod() const override {
        return "Electronic wallet";
    }
};

class SBPPayment : public PaymentStrategy {
public:
    bool pay(double amount) override {
        cout << "Payment via SBP for amount: " << amount << " rub." << endl;
        return true;
    }

    string getPaymentMethod() const override {
        return "Fast payment system";
    }
};


class Payment {
private:
    unique_ptr<PaymentStrategy> strategy;
    double amount;
    bool paid;

public:
    Payment(double amt) : amount(amt), paid(false) {}

    void setStrategy(unique_ptr<PaymentStrategy> strat) {
        strategy = move(strat);
    }

    bool processPayment() {
        if (!strategy) {
            cerr << "Payment method not selected" << endl;
            return false;
        }
        paid = strategy->pay(amount);
        return paid;
    }

    bool isPaid() const { return paid; }
    double getAmount() const { return amount; }
};


class OrderItem {
private:
    int product_id;
    string product_name;
    int quantity;
    double price;

public:
    OrderItem(int pid, const  string& pname, int qty, double pr)
        : product_id(pid), product_name(pname), quantity(qty), price(pr) {
    }

    int getProductId() const { return product_id; }
    string getProductName() const { return product_name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    double getTotalPrice() const { return quantity * price; }

    void setQuantity(int qty) { quantity = qty; }
};


class Order {
private:
    int order_id;
    int user_id;
    string status;
    double total_price;
    string order_date;
    vector< unique_ptr<OrderItem>> items;
    unique_ptr<Payment> payment;

public:
    Order(int oid, int uid, const  string& stat = "pending")
        : order_id(oid), user_id(uid), status(stat), total_price(0.0) {
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        char buffer[100];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now_time));
        order_date = buffer;
    }

    void addItem(unique_ptr<OrderItem> item) {
        total_price += item->getTotalPrice();
        items.push_back(move(item));
    }

    void removeItem(int product_id) {
        auto it = find_if(items.begin(), items.end(),
            [product_id](const  unique_ptr<OrderItem>& item) {
                return item->getProductId() == product_id;
            });

        if (it != items.end()) {
            total_price -= (*it)->getTotalPrice();
            items.erase(it);
        }
    }

    void createPayment() {
        payment = make_unique<Payment>(total_price);
    }

    Payment* getPayment() { return payment.get(); }

    int getOrderId() const { return order_id; }
    int getUserId() const { return user_id; }
    string getStatus() const { return status; }
    void setStatus(const  string& stat) { status = stat; }
    double getTotalPrice() const { return total_price; }
    string getOrderDate() const { return order_date; }
    const  vector< unique_ptr<OrderItem>>& getItems() const { return items; }

    void displayOrder() const {
        cout << "\n         Order #" << order_id << "         " << endl;
        cout << "Status: " << status << endl;
        cout << "Date: " << order_date << endl;
        cout << "Products:" << endl;
        for (const auto& item : items) {
            cout << "  - " << item->getProductName()
                << " x" << item->getQuantity()
                << " = " << item->getTotalPrice() << " rub." << endl;
        }
        cout << "Total: " << total_price << " rub." << endl;
    }
};


class User {
protected:
    int user_id;
    string name;
    string email;
    string role;
    int loyalty_level;
    vector< shared_ptr<Order>> orders;
    DatabaseConnection< string>* db;

public:
    User(int uid, const  string& n, const  string& e, const  string& r, int loyalty, DatabaseConnection< string>* database)
        : user_id(uid), name(n), email(e), role(r), loyalty_level(loyalty), db(database) {
    }

    virtual ~User() = default;

    virtual void showMenu() = 0;

    int getUserId() const { return user_id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getRole() const { return role; }

    shared_ptr<Order> createOrder() {
        try {
            string query = "SELECT COALESCE(MAX(order_id), 0) + 1 FROM orders";
            auto result = db->executeQuery(query);
            int new_order_id = stoi(result[0][0]);

            auto order = make_shared<Order>(new_order_id, user_id);
            orders.push_back(order);

            cout << "Created new order #" << new_order_id << endl;
            return order;
        }
        catch (const  exception& e) {
            cerr << "Order creation error: " << e.what() << endl;
            return nullptr;
        }
    }

    void viewOrderStatus(int order_id) {
        try {
            string query = "SELECT status FROM orders WHERE order_id = " + to_string(order_id);
            auto result = db->executeQuery(query);

            if (!result.empty()) {
                cout << "Order status #" << order_id << ": " << result[0][0] << endl;
            }
            else {
                cout << "Order not found" << endl;
            }
        }
        catch (const  exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void cancelOrder(int order_id) {
        try {
            string query = "UPDATE orders SET status = 'canceled' WHERE order_id = " + to_string(order_id) + " AND user_id = " + to_string(user_id);
            db->executeNonQuery(query);
            cout << "Order #" << order_id << " canceled" << endl;
        }
        catch (const  exception& e) {
            cerr << "Order cancellation error: " << e.what() << endl;
        }
    }

    vector< shared_ptr<Order>>& getOrders() { return orders; }
};


class Admin : public User {
public:
    Admin(int uid, const  string& n, const  string& e, int loyalty, DatabaseConnection< string>* database)
        : User(uid, n, e, "admin", loyalty, database) {
    }

    void showMenu() override {
        cout << "\n         ADMIN MENU         " << endl;
        cout << "1. Add new product" << endl;
        cout << "2. Update product information" << endl;
        cout << "3. Delete product" << endl;
        cout << "4. View all orders" << endl;
        cout << "5. Change order status" << endl;
        cout << "6. View order status history" << endl;
        cout << "7. View audit log" << endl;
        cout << "8. Generate report (CSV)" << endl;
        cout << "9. Show products" << endl;
        cout << "0. Exit" << endl;
    }

    void addProduct(const  string& name, double price, int stock) {
        try {
            db->beginTransaction();

            string query = "INSERT INTO products (name, price, stock_quantity) VALUES ('" + name + "', " + to_string(price) + ", " + to_string(stock) + ")";
            db->executeInTransaction(query);

            db->commitTransaction();
            cout << "Product '" << name << "' added successfully" << endl;
        }
        catch (const  exception& e) {
            db->rollbackTransaction();
            cerr << "Product addition error: " << e.what() << endl;
        }
    }
    void viewProducts() {
        try {
            db->beginTransaction();

            string query = "SELECT product_id, name, price, stock_quantity FROM products ORDER BY product_id";
            auto result = db->executeInTransaction(query);

            db->commitTransaction();

            cout << "\nPRODUCT LIST" << endl;
            cout << "ID |    Name      |   Price   | Stock" << endl;
            cout << "--------------------------------" << endl;

            for (const auto& row : result) {
                cout << row[0].c_str() << " | "<< row[1].c_str() << "  "<< row[2].c_str() << "  " << row[3].c_str() << endl;
            }
        }
        catch (const exception& e) {
            db->rollbackTransaction();
            cerr << "Error viewing products: " << e.what() << endl;
        }
    }
    void updateProduct(int product_id, const  string& name, double price, int stock) {
        try {
            string query = "UPDATE products SET name = '" + name
                + "', price = " + to_string(price)
                + ", stock_quantity = " + to_string(stock)
                + " WHERE product_id = " + to_string(product_id);
            db->executeNonQuery(query);
            cout << "Product #" << product_id << " updated" << endl;
        }
        catch (const  exception& e) {
            cerr << "Product update error: " << e.what() << endl;
        }
    }

    void deleteProduct(int product_id) {
        try {
            string query = "DELETE FROM products WHERE product_id = " + to_string(product_id);
            db->executeNonQuery(query);
            cout << "Product #" << product_id << " deleted" << endl;
        }
        catch (const  exception& e) {
            cerr << "Product deletion error: " << e.what() << endl;
        }
    }

    void viewAllOrders() {
        try {
            string query = "SELECT order_id, user_id, status, total_price, order_date FROM orders ORDER BY order_id";
            auto result = db->executeQuery(query);

            cout << "\n         ALL ORDERS         " << endl;
            for (const auto& row : result) {
                cout << "Order #" << row[0] << " | User: " << row[1]
                    << " | Status: " << row[2] << " | Amount: " << row[3]
                    << " | Date: " << row[4] << endl;
            }
        }
        catch (const  exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void updateOrderStatus(int order_id, const  string& new_status) {
        try {
            string query = "SELECT update_order_status(" + to_string(order_id)
                + ", '" + new_status + "', " + to_string(user_id) + ")";
            db->executeQuery(query);
            cout << "Order status #" << order_id << " changed to '" << new_status << "'" << endl;
        }
        catch (const  exception& e) {
            cerr << "Status change error: " << e.what() << endl;
        }
    }

    void viewOrderStatusHistory(int order_id) {
        try {
            string query = "SELECT * FROM get_order_status_history(" + to_string(order_id) + ")";
            auto result = db->executeQuery(query);

            cout << "\n         ORDER STATUS HISTORY #" << order_id << "         " << endl;
            for (const auto& row : result) {
                cout << row[0] << " -> " << row[1] << " | " << row[2]
                    << " | Changed by: user #" << row[3] << endl;
            }
        }
        catch (const  exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void viewAuditLog() {
        try {
            string query = "SELECT * FROM audit_log ORDER BY performed_at DESC LIMIT 50";
            auto result = db->executeQuery(query);
            cout << "\n         AUDIT LOG         " << endl;
            for (const auto& row : result) {
                cout << row[5] << " | " << row[1] << " #" << row[2] << " | " << row[3] << " | User #" << row[4] << endl;
            }
        }
        catch (const  exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void generateCSVReport(const  string& filename) {
        try {
            string query = R"(
                SELECT 
                    o.order_id,
                    o.user_id,
                    o.status,
                    o.total_price,
                    o.order_date,
                    osh.old_status,
                    osh.new_status,
                    osh.changed_at,
                    osh.changed_by,
                    al.operation,
                    al.performed_at
                FROM orders o
                LEFT JOIN order_status_history osh ON o.order_id = osh.order_id
                LEFT JOIN audit_log al ON al.entity_type = 'order' AND al.entity_id = o.order_id
                ORDER BY o.order_id, osh.changed_at, al.performed_at
            )";

            auto result = db->executeQuery(query);

            ofstream file(filename);
            if (!file.is_open()) {
                throw  runtime_error("Failed to create file");
            }

            file << "OrderID,UserID,Status,TotalPrice,OrderDate,OldStatus,NewStatus,ChangedAt,ChangedBy,Operation,PerformedAt\n";

            for (const auto& row : result) {
                for (size_t i = 0; i < row.size(); ++i) {
                    file << row[i];
                    if (i < row.size() - 1) file << ",";
                }
                file << "\n";
            }

            file.close();
            cout << "Report saved to file: " << filename << endl;
        }
        catch (const  exception& e) {
            cerr << "Report creation error: " << e.what() << endl;
        }
    }
};


class Manager : public User {
public:
    Manager(int uid, const  string& n, const  string& e, int loyalty, DatabaseConnection< string>* database)
        : User(uid, n, e, "manager", loyalty, database) {
    }

    void showMenu() override {
        cout << "\n         MANAGER MENU         " << endl;
        cout << "1. View orders pending approval" << endl;
        cout << "2. Approve order" << endl;
        cout << "3. Update product stock quantity" << endl;
        cout << "4. Show products" << endl;
        cout << "0. Exit" << endl;
    }

    void approveOrder(int order_id) {
        try {
            string query = "SELECT update_order_status(" + to_string(order_id)
                + ", 'completed', " + to_string(user_id) + ")";
            db->executeQuery(query);
            cout << "Order #" << order_id << " approved" << endl;
        }
        catch (const  exception& e) {
            cerr << "Order approval error: " << e.what() << endl;
        }
    }
    void viewProducts() {
        try {
            string query = "SELECT product_id, name, price, stock_quantity FROM products ORDER BY product_id";
            auto result = db->executeQuery(query);

            cout << "\nPRODUCT LIST" << endl;
            cout << "ID  |       Name                | Price    | Stock" << endl;
            cout << "--------------------------------" << endl;

            for (const auto& row : result) {
                cout << setw(3) << row[0] << " | "
                    << setw(24) << left << row[1] << " | "
                    << setw(8) << right << row[2] << " | "
                    << setw(5) << row[3] << endl;
            }

            cout << "--------------------------------" << endl;
            cout << "Total products: " << result.size() << endl;
        }
        catch (const exception& e) {
            cerr << "Error viewing products: " << e.what() << endl;
        }
    }
    void updateStock(int product_id, int new_quantity) {
        try {
            string query = "UPDATE products SET stock_quantity = " + to_string(new_quantity) + " WHERE product_id = " + to_string(product_id);
            db->executeNonQuery(query);
            cout << "Product quantity #" << product_id << " updated" << endl;
        }
        catch (const  exception& e) {
            cerr << "Stock update error: " << e.what() << endl;
        }
    }

    void viewPendingOrders() {
        try {
            string query = "SELECT order_id, user_id, total_price, order_date FROM orders WHERE status = 'pending'";
            auto result = db->executeQuery(query);

            cout << "\n         PENDING ORDERS         " << endl;
            for (const auto& row : result) {
                cout << "Order #" << row[0] << " | User: " << row[1]
                    << " | Amount: " << row[2] << " | Date: " << row[3] << endl;
            }
        }
        catch (const  exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
};


class Customer : public User {
private:
    shared_ptr<Order> current_order;

public:
    Customer(int uid, const  string& n, const  string& e, int loyalty, DatabaseConnection< string>* database)
        : User(uid, n, e, "customer", loyalty, database), current_order(nullptr) {
    }

    void showMenu() override {
        cout << "\n         CUSTOMER MENU         " << endl;
        cout << "1. Create new order" << endl;
        cout << "2. Add product to order" << endl;
        cout << "3. Remove product from order" << endl;
        cout << "4. View my orders" << endl;
        cout << "5. View order status" << endl;
        cout << "6. Pay for order" << endl;
        cout << "7. Process order return" << endl;
        cout << "8. Show products" << endl;
        cout << "0. Exit" << endl;
    }

    void startNewOrder() {
        current_order = createOrder();
        if (current_order) {
            current_order->createPayment();
        }
    }
    void viewProducts() {
        try {
            string query = "SELECT product_id, name, price, stock_quantity FROM products ORDER BY product_id";
            auto result = db->executeQuery(query);

            cout << "\nPRODUCT LIST" << endl;
            cout << "ID  |       Name                | Price    | Stock" << endl;
            cout << "--------------------------------" << endl;

            for (const auto& row : result) {
                cout << setw(3) << row[0] << " | "
                    << setw(24) << left << row[1] << " | "
                    << setw(8) << right << row[2] << " | "
                    << setw(5) << row[3] << endl;
            }

            cout << "--------------------------------" << endl;
            cout << "Total products: " << result.size() << endl;
        }
        catch (const exception& e) {
            cerr << "Error viewing products: " << e.what() << endl;
        }
    }
    void addToOrder(int product_id, int quantity) {
        if (!current_order) {
            cout << "Create an order first!" << endl;
            return;
        }

        try {
            string query = "SELECT name, price, stock_quantity FROM products WHERE product_id = "
                + to_string(product_id);
            auto result = db->executeQuery(query);

            if (result.empty()) {
                cout << "Product not found" << endl;
                return;
            }

            string name = result[0][0];
            double price = stod(result[0][1]);
            int stock = stoi(result[0][2]);

            if (stock < quantity) {
                cout << "Insufficient stock" << endl;
                return;
            }

            auto item = make_unique<OrderItem>(product_id, name, quantity, price);
            current_order->addItem(move(item));

            cout << "Product added to order" << endl;
        }
        catch (const  exception& e) {
            cerr << "Product addition error: " << e.what() << endl;
        }
    }

    void removeFromOrder(int product_id) {
        if (!current_order) {
            cout << "No active order" << endl;
            return;
        }

        current_order->removeItem(product_id);
        cout << "Product removed from order" << endl;
    }

    void makePayment() {
        if (!current_order) {
            cout << "No active order" << endl;
            return;
        }

        cout << "\nSelect payment method:" << endl;
        cout << "1. Bank card" << endl;
        cout << "2. Electronic wallet" << endl;
        cout << "3. SBP" << endl;

        int choice;
        cin >> choice;

        Payment* payment = current_order->getPayment();
        if (!payment) {
            cout << "Error: payment not initialized" << endl;
            return;
        }

        switch (choice) {
        case 1:
            payment->setStrategy(make_unique<CardPayment>());
            break;
        case 2:
            payment->setStrategy(make_unique<EWalletPayment>());
            break;
        case 3:
            payment->setStrategy(make_unique<SBPPayment>());
            break;
        default:
            cout << "Invalid choice" << endl;
            return;
        }

        if (payment->processPayment()) {
            saveOrderToDatabase();
            cout << "Order successfully paid and saved!" << endl;
            current_order = nullptr;
        }
    }

    void saveOrderToDatabase() {
        if (!current_order) return;

        try {
            db->beginTransaction();

            string insert_order = "INSERT INTO orders (order_id, user_id, status, total_price, order_date) VALUES ("
                + to_string(current_order->getOrderId()) + ", "
                + to_string(user_id) + ", "
                + "'completed', "
                + to_string(current_order->getTotalPrice()) + ", "
                + "CURRENT_TIMESTAMP)";
            db->executeInTransaction(insert_order);

            for (const auto& item : current_order->getItems()) {
                string insert_item = "INSERT INTO order_items (order_id, product_id, quantity, price) VALUES ("
                    + to_string(current_order->getOrderId()) + ", "
                    + to_string(item->getProductId()) + ", "
                    + to_string(item->getQuantity()) + ", "
                    + to_string(item->getPrice()) + ")";
                db->executeInTransaction(insert_item);

                string update_stock = "UPDATE products SET stock_quantity = stock_quantity - "
                    + to_string(item->getQuantity())
                    + " WHERE product_id = " + to_string(item->getProductId());
                db->executeInTransaction(update_stock);
            }

            db->commitTransaction();
        }
        catch (const  exception& e) {
            db->rollbackTransaction();
            cerr << "Order save error: " << e.what() << endl;
        }
    }

    void viewMyOrders() {
        try {
            string query = "SELECT order_id, status, total_price, order_date FROM orders WHERE user_id = "
                + to_string(user_id);
            auto result = db->executeQuery(query);

            cout << "\n         MY ORDERS         " << endl;
            for (const auto& row : result) {
                cout << "Order #" << row[0] << " | Status: " << row[1]
                    << " | Amount: " << row[2] << " | Date: " << row[3] << endl;
            }
        }
        catch (const  exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void returnOrder(int order_id) {
        try {
            string check_query = "SELECT can_return_order(" + to_string(order_id) + ")";
            auto result = db->executeQuery(check_query);

            if (result.empty() || result[0][0] != "t") {
                cout << "Order return not possible (order must be completed and no more than 30 days passed)" << endl;
                return;
            }

            string update_query = "SELECT update_order_status(" + to_string(order_id)
                + ", 'returned', " + to_string(user_id) + ")";
            db->executeQuery(update_query);
            cout << "Order #" << order_id << " returned" << endl;
        }
        catch (const  exception& e) {
            cerr << "Order return error: " << e.what() << endl;
        }
    }

    void displayCurrentOrder() {
        if (current_order) {
            current_order->displayOrder();
        }
        else {
            cout << "No active order" << endl;
        }
    }
};


vector< shared_ptr<Order>> filterOrdersByStatus(
    const  vector< shared_ptr<Order>>& orders,
    const  string& status) {

    vector< shared_ptr<Order>> filtered;

    copy_if(orders.begin(), orders.end(), back_inserter(filtered),
        [&status](const  shared_ptr<Order>& order) {
            return order->getStatus() == status;
        });

    return filtered;
}

double calculateTotalAmount(const  vector< shared_ptr<Order>>& orders) {
    return  accumulate(orders.begin(), orders.end(), 0.0,
        [](double sum, const  shared_ptr<Order>& order) {
            return sum + order->getTotalPrice();
        });
}

int countOrdersByStatus(const  vector< shared_ptr<Order>>& orders,
    const  string& status) {
    return  count_if(orders.begin(), orders.end(),
        [&status](const  shared_ptr<Order>& order) {
            return order->getStatus() == status;
        });
}

bool checkUserPermission(const  string& user_role, const  string& required_role) {
    auto permission_check = [](const  string& role, const  string& required) -> bool {
        if (required == "admin") return role == "admin";
        if (required == "manager") return role == "admin" || role == "manager";
        return true;
        };

    return permission_check(user_role, required_role);
}


void initializeDatabase(DatabaseConnection< string>& db) {
    try {
        cout << "\nInitializing database..." << endl;

        // Create order status update function
        string create_update_status_func = R"(
            CREATE OR REPLACE FUNCTION update_order_status(
                p_order_id INTEGER,
                p_new_status VARCHAR,
                p_user_id INTEGER
            ) RETURNS VOID AS $$
            DECLARE
                v_old_status VARCHAR;
            BEGIN
                SELECT status INTO v_old_status FROM orders WHERE order_id = p_order_id;
                
                UPDATE orders SET status = p_new_status WHERE order_id = p_order_id;
                
                INSERT INTO order_status_history (order_id, old_status, new_status, changed_by)
                VALUES (p_order_id, v_old_status, p_new_status, p_user_id);
            END;
            $$ LANGUAGE plpgsql;
        )";
        db.createFunction(create_update_status_func);

        string create_history_func = R"(
            CREATE OR REPLACE FUNCTION get_order_status_history(p_order_id INTEGER)
            RETURNS TABLE(old_status VARCHAR, new_status VARCHAR, changed_at TIMESTAMP, changed_by INTEGER) AS $$
            BEGIN
                RETURN QUERY
                SELECT osh.old_status, osh.new_status, osh.changed_at, osh.changed_by
                FROM order_status_history osh
                WHERE osh.order_id = p_order_id
                ORDER BY osh.changed_at;
            END;
            $$ LANGUAGE plpgsql;
        )";
        db.createFunction(create_history_func);

        string create_return_func = R"(
            CREATE OR REPLACE FUNCTION can_return_order(p_order_id INTEGER)
            RETURNS BOOLEAN AS $$
            DECLARE
                v_status VARCHAR;
                v_order_date TIMESTAMP;
            BEGIN
                SELECT status, order_date INTO v_status, v_order_date
                FROM orders WHERE order_id = p_order_id;
                
                RETURN v_status = 'completed' AND 
                       CURRENT_TIMESTAMP - v_order_date <= INTERVAL '30 days';
            END;
            $$ LANGUAGE plpgsql;
        )";
        db.createFunction(create_return_func);

        cout << "Database initialized successfully!" << endl;
    }
    catch (const  exception& e) {
        cerr << "Database initialization error: " << e.what() << endl;
    }
}


int main() {/*
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");*/


    try {
        string connection_string = "host=localhost user=postgres password=1234 dbname=online_store3";
        DatabaseConnection< string> db(connection_string);

        initializeDatabase(db);
        auto admin = make_unique<Admin>(1, "Ivan Adminov", "admin@store.com", 1, &db);
        auto manager = make_unique<Manager>(2, "Petr Managerov", "manager@store.com", 0, &db);
        auto customer = make_unique<Customer>(3, "Aleksey Pokupatelev", "customer@store.com", 0, &db);

        while (true) {
            cout << "ONLINE STORE SYSTEM" << endl;
            cout << "1. Log in as Administrator" << endl;
            cout << "2. Log in as Manager" << endl;
            cout << "3. Log in as Customer" << endl;
            cout << "0. Exit" << endl;
            cout << "Select role: ";

            int role_choice;
            cin >> role_choice;

            if (role_choice == 0) break;

            User* current_user = nullptr;

            switch (role_choice) {
            case 1:
                current_user = admin.get();
                break;
            case 2:
                current_user = manager.get();
                break;
            case 3:
                current_user = customer.get();
                break;
            default:
                cout << "Invalid choice!" << endl;
                continue;
            }
            while (true) {
                current_user->showMenu();
                cout << "Select action: ";

                int action;
                cin >> action;

                if (action == 0) break;

                if (role_choice == 1) {
                    Admin* adm = static_cast<Admin*>(current_user);
                    switch (action) {
                    case 1: {
                        string name;
                        double price;
                        int stock;
                        cout << "Product name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Price: ";
                        cin >> price;
                        cout << "Quantity: ";
                        cin >> stock;
                        adm->addProduct(name, price, stock);
                        break;
                    }
                    case 2: {
                        int pid;
                        string name;
                        double price;
                        int stock;
                        cout << "Product ID: ";
                        cin >> pid;
                        cout << "New name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "New price: ";
                        cin >> price;
                        cout << "New quantity: ";
                        cin >> stock;
                        adm->updateProduct(pid, name, price, stock);
                        break;
                    }
                    case 3: {
                        int pid;
                        cout << "Product ID to delete: ";
                        cin >> pid;
                        adm->deleteProduct(pid);
                        break;
                    }
                    case 4:
                        adm->viewAllOrders();
                        break;
                    case 5: {
                        int oid;
                        string status;
                        cout << "Order ID: ";
                        cin >> oid;
                        cout << "New status (pending/completed/canceled/returned): ";
                        cin >> status;
                        adm->updateOrderStatus(oid, status);
                        break;
                    }
                    case 6: {
                        int oid;
                        cout << "Order ID: ";
                        cin >> oid;
                        adm->viewOrderStatusHistory(oid);
                        break;
                    }
                    case 7: {
                        adm->viewAuditLog();
                        break;
                    }
                    case 8: {
                        adm->generateCSVReport("audit_report.csv");
                        break;
                    }
                    case 9: {
                        adm->viewProducts();
                        break;
                    }
                    }
                }
                else if (role_choice == 2) {
                    Manager* mgr = static_cast<Manager*>(current_user);
                    switch (action) {
                    case 1:
                        mgr->viewPendingOrders();
                        break;
                    case 2: {
                        int oid;
                        cout << "Order ID to approve: ";
                        cin >> oid;
                        mgr->approveOrder(oid);
                        break;
                    }
                    case 3: {
                        int pid, qty;
                        cout << "Product ID: ";
                        cin >> pid;
                        cout << "New quantity: ";
                        cin >> qty;
                        mgr->updateStock(pid, qty);
                        break;
                    }
                    case 4: {
                        mgr->viewProducts();
                        break;
                    }
                    }
                }
                else if (role_choice == 3) {
                    Customer* cust = static_cast<Customer*>(current_user);
                    switch (action) {
                    case 1:
                        cust->startNewOrder();
                        break;
                    case 2: {
                        int pid, qty;
                        cout << "Product ID: ";
                        cin >> pid;
                        cout << "Quantity: ";
                        cin >> qty;
                        cust->addToOrder(pid, qty);
                        cust->displayCurrentOrder();
                        break;
                    }
                    case 3: {
                        int pid;
                        cout << "Product ID to remove: ";
                        cin >> pid;
                        cust->removeFromOrder(pid);
                        break;
                    }
                    case 4:
                        cust->viewMyOrders();
                        break;
                    case 5: {
                        int oid;
                        cout << "Order ID: ";
                        cin >> oid;
                        cust->viewOrderStatus(oid);
                        break;
                    }
                    case 6:
                        cust->makePayment();
                        break;
                    case 7: {
                        int oid;
                        cout << "Order ID for return: ";
                        cin >> oid;
                        cust->returnOrder(oid);
                        break;
                    }
                    case 8: {
                        cust->viewProducts();
                        break;
                    }
                    }
                }
            }
        }

        cout << "\nThank you for using the system!" << endl;
    }
    catch (const  exception& e) {
        cerr << "Critical error: " << e.what() << endl;
        return 1;
    }

    return 0;
}

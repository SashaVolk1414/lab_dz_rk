#include <iostream>
#include<locale>
#include<fstream>
#include<map>
#include<vector>
#include<numeric>
#include<string>
#include<sstream>
using namespace std;

struct Student {
    int id;
    char name[50];
    int age;
    double average_grade;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    //Задача 1
    /*
    ifstream fin("in.txt", ios::in);
    ofstream fout("out.txt", ios::app);
    string poisk;
    vector<std::pair<int, int>> points;
    cout << "Введите слово: " << endl;
    cin >> poisk;
    int k = 0, s = 0; bool naid = false;
    if (fin.is_open()) {
        if (fout.is_open()) {
            string line;
            while (getline(fin, line)) {
                k++;
                istringstream iss(line);
                string word;
                while (iss >> word) {
                    s++;
                    if (word == poisk) {
                        fout << "Слово " << word << " найде в строке " << k << " в позиции " << s << endl;
                        points.push_back({ k, s });
                    }
                }
                s = 0;
            }
        }
    }
    else { cout << "Ошибка, открытия файла" << endl; }
    fout << "Кол-во найденных слов: " << points.size();
    fout.close(); fin.close();*/
    //Задача 2
    /*string l="timeout=";
    string k="60";
    fstream f("inout.txt", ios::in | ios::out);
    if (f.is_open()) {
        string line;
        streampos pos = f.tellp();
        while (getline(f, line)) {
            if (line.find(l) == 0) {
                string news = l+k;
                f.seekp(pos);
                f << news;
            }
            pos = f.tellp();
        }
    }
    f.close();*/
    //Задача 3
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <iomanip>
//
//    using namespace std;
//
//    class LogSplitter {
//    private:
//        string inputFilename;
//        vector<string> outputFilenames;
//        vector<pair<string, long long>> fileInfo;
//
//    public:
//        LogSplitter(const string& filename) : inputFilename(filename) {}
//
//        void splitLogFile(int maxParts = 10, long long maxSizePerFile = 1024 * 1024) {
//            ifstream inputFile(inputFilename, ios::binary);
//
//            if (!inputFile.is_open()) {
//                cerr << "Ошибка: не удалось открыть файл " << inputFilename << endl;
//                return;
//            }
//
//            inputFile.seekg(0, ios::end);
//            long long totalSize = inputFile.tellg();
//            inputFile.seekg(0, ios::beg);
//
//            cout << "Размер исходного файла: " << totalSize << " байт" << endl;
//
//            if (maxSizePerFile <= 0) {
//                maxSizePerFile = (totalSize + maxParts - 1) / maxParts;
//            }
//
//            int partNumber = 1;
//            long long bytesProcessed = 0;
//
//            while (bytesProcessed < totalSize) {
//                ostringstream filenameStream;
//                filenameStream << "log_part" << partNumber << ".txt";
//                string outputFilename = filenameStream.str();
//
//                ofstream outputFile(outputFilename, ios::binary);
//
//                if (!outputFile.is_open()) {
//                    cerr << "Ошибка: не удалось создать файл " << outputFilename << endl;
//                    return;
//                }
//
//                long long bytesToWrite = min(maxSizePerFile, totalSize - bytesProcessed);
//                long long endPosition = bytesProcessed + bytesToWrite;
//
//                inputFile.seekg(bytesProcessed, ios::beg);
//
//                if (endPosition < totalSize) {
//                    inputFile.seekg(endPosition, ios::beg);
//
//                    string line;
//                    getline(inputFile, line);
//
//                    long long actualEnd = inputFile.tellg();
//
//                    if (actualEnd > 0) {
//                        bytesToWrite = actualEnd - bytesProcessed;
//                    }
//                }
//
//                inputFile.seekg(bytesProcessed, ios::beg);
//
//                vector<char> buffer(bytesToWrite);
//                inputFile.read(buffer.data(), bytesToWrite);
//                outputFile.write(buffer.data(), bytesToWrite);
//
//                outputFilenames.push_back(outputFilename);
//                fileInfo.push_back({ outputFilename, bytesToWrite });
//
//                cout << "Создан файл: " << outputFilename << " (" << bytesToWrite << " байт)" << endl;
//
//                bytesProcessed += bytesToWrite;
//                partNumber++;
//
//                outputFile.close();
//            }
//
//            inputFile.close();
//
//            createIndexFile();
//
//            cout << "Файл разделен на " << outputFilenames.size() << " частей" << endl;
//        }
//
//        void createIndexFile() {
//            ofstream indexFile("log_index.txt");
//
//            if (!indexFile.is_open()) {
//                cerr << "Ошибка: не удалось создать индексный файл" << endl;
//                return;
//            }
//
//            indexFile << "Индекс разделенных лог-файлов" << endl;
//            indexFile << "==============================" << endl << endl;
//
//            long long totalSize = 0;
//            for (size_t i = 0; i < fileInfo.size(); ++i) {
//                indexFile << "Часть " << (i + 1) << ": " << fileInfo[i].first;
//                indexFile << " (" << fileInfo[i].second << " байт)" << endl;
//                totalSize += fileInfo[i].second;
//            }
//
//            indexFile << endl << "Итого: " << fileInfo.size() << " файлов, ";
//            indexFile << totalSize << " байт" << endl;
//
//            indexFile.close();
//
//            cout << "Создан индексный файл: log_index.txt" << endl;
//        }
//    };
//
//    int main() {
//        LogSplitter splitter("application.log");
//        splitter.splitLogFile();
//
//        return 0;
//    }
    //Задача 4
    /*int numbers[] = { 15, 23, 7, 42, 18, 91, 3, 56, 77, 10 };
    int sizek = sizeof(numbers) / sizeof(numbers[0]);
    ofstream fout("numbers.bin", std::ios::binary);
    if (fout.is_open()) {
        fout.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
    }
    else {
        cout << "Ошибка 1" << endl;
    }
    fout.close();
    ifstream file("numbers.bin", ios::binary);
    vector <int> buffer(sizek);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(buffer.data()), sizeof(numbers));
        cout << "Массив: ";
        auto sums = accumulate(buffer.begin(), buffer.end(), 0);
        for (auto i : buffer) {
            cout << i<<" ";
        }
        cout << endl;
        file.seekg(0, std::ios::end);
        size_t file_size = file.tellg();
        file.seekg(0, std::ios::beg);
        cout << "Размер файла: " << file_size;
        cout << "Сумма всех чисел: " << sums;
    }
    else {
        cout << "Ошибка 2" << endl;
    }*/
    //Задача 5
    /*Student students[] = {
    {1, "Иван Петров", 20, 4.5},
    {2, "Мария Сидорова", 19, 4.8},
    {3, "Алексей Иванов", 21, 4.2}
    };
    ofstream fout("students.dat ", std::ios::binary);
    if (fout.is_open()) {
        fout.write(reinterpret_cast<char*>(students), sizeof(students));
    }
    else {
        cout << "Ошибка 1" << endl;
    }
    fout.close();
    ifstream file("students.dat", ios::binary);
    vector <Student> buffer;
    if (file.is_open()) {
        file.seekg(0, ios::end); 
        streamsize file_size = file.tellg(); 
        file.seekg(0, ios::beg); 

        int student_count = file_size / sizeof(Student);
        buffer.resize(student_count); 
        file.read(reinterpret_cast<char*>(buffer.data()), sizeof(students));
        for (auto i : buffer) {
            cout << i.id << " " << i.name << " " << i.age << " " << i.average_grade << endl;
        }
        auto s = max_element(buffer.begin(), buffer.end(), [](const Student& a, const Student& b) { return a.average_grade < b.average_grade; });
        int sizek = size(buffer);
        auto id = distance(buffer.begin(), s);
        cout << "студент с самым высоким средним баллом: " << buffer[id].name << endl;
        cout << "количество студентов в файле: " << sizek << endl;
    }*/
//Задача 6
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <iomanip>
//
//using namespace std;
//
//struct Product {
//    int id;
//    string name;
//    string category;
//    double price;
//    int quantity;
//};
//
//vector<string> productNames = {
//    "Ноутбук Dell", "Мышь Bluetooth", "Клавиатура механическая", "Монитор 27 дюймов",
//    "Наушники беспроводные", "Смартфон Samsung", "Планшет Apple", "Флешка 64GB",
//    "Внешний жесткий диск", "Роутер Wi-Fi", "Принтер лазерный", "Сканер документов",
//    "Веб-камера", "Микрофон USB", "Колонки стерео", "Игровая консоль", "Джойстик",
//    "Коврик для мыши", "Сетевой кабель", "Блок питания"
//};
//
//vector<string> categories = {
//    "Электроника", "Аксессуары", "Компьютеры", "Периферия", "Офисная техника"
//};
//
//Product generateProduct(int id) {
//    Product product;
//    product.id = id;
//
//    int nameIndex = rand() % productNames.size();
//    product.name = productNames[nameIndex];
//
//    int categoryIndex = rand() % categories.size();
//    product.category = categories[categoryIndex];
//
//    product.price = 100 + rand() % 9901;
//    product.quantity = 1 + rand() % 100;
//
//    return product;
//}
//
//void createCSVFile() {
//    ofstream file("products.csv");
//
//    if (!file.is_open()) {
//        cerr << "Ошибка: не удалось создать файл products.csv" << endl;
//        return;
//    }
//
//    file << "id,name,category,price,quantity" << endl;
//
//    for (int i = 1; i <= 20; i++) {
//        Product product = generateProduct(i);
//
//        file << product.id << ",";
//        file << product.name << ",";
//        file << product.category << ",";
//        file << fixed << setprecision(2) << product.price << ",";
//        file << product.quantity << endl;
//    }
//
//    file.close();
//
//    cout << "Файл products.csv успешно создан" << endl;
//}
//
//void verifyCSVFile() {
//    ifstream file("products.csv");
//
//    if (!file.is_open()) {
//        cerr << "Ошибка: не удалось открыть файл products.csv" << endl;
//        return;
//    }
//
//    string line;
//    int lineCount = 0;
//
//    while (getline(file, line)) {
//        lineCount++;
//    }
//
//    file.close();
//
//    cout << "Проверка файла:" << endl;
//    cout << "Всего строк в файле: " << lineCount << endl;
//    cout << "Записей с товарами: " << (lineCount - 1) << endl;
//
//    if (lineCount == 21) {
//        cout << "Файл содержит правильное количество записей (20 товаров + заголовок)" << endl;
//    }
//    else {
//        cout << "Внимание: количество записей не соответствует ожидаемому!" << endl;
//    }
//}
//
//int main() {
//    srand(time(0));
//
//    createCSVFile();
//    verifyCSVFile();
//
//    return 0;
//}
// Задача 7
// #include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <iomanip>
//
//using namespace std;
//
//struct Product {
//    int id;
//    string name;
//    string category;
//    double price;
//    int quantity;
//};
//
//vector<string> productNames = {
//    "Ноутбук Dell", "Мышь Bluetooth", "Клавиатура механическая", "Монитор 27 дюймов",
//    "Наушники беспроводные", "Смартфон Samsung", "Планшет Apple", "Флешка 64GB",
//    "Внешний жесткий диск", "Роутер Wi-Fi", "Принтер лазерный", "Сканер документов",
//    "Веб-камера", "Микрофон USB", "Колонки стерео", "Игровая консоль", "Джойстик",
//    "Коврик для мыши", "Сетевой кабель", "Блок питания"
//};
//
//vector<string> categories = {
//    "Электроника", "Аксессуары", "Компьютеры", "Периферия", "Офисная техника"
//};
//
//Product generateProduct(int id) {
//    Product product;
//    product.id = id;
//
//    int nameIndex = rand() % productNames.size();
//    product.name = productNames[nameIndex];
//
//    int categoryIndex = rand() % categories.size();
//    product.category = categories[categoryIndex];
//
//    product.price = 100 + rand() % 9901;
//    product.quantity = 1 + rand() % 100;
//
//    return product;
//}
//
//void createCSVFile() {
//    ofstream file("products.csv");
//
//    if (!file.is_open()) {
//        cerr << "Ошибка: не удалось создать файл products.csv" << endl;
//        return;
//    }
//
//    file << "id,name,category,price,quantity" << endl;
//
//    for (int i = 1; i <= 20; i++) {
//        Product product = generateProduct(i);
//
//        file << product.id << ",";
//        file << product.name << ",";
//        file << product.category << ",";
//        file << fixed << setprecision(2) << product.price << ",";
//        file << product.quantity << endl;
//    }
//
//    file.close();
//
//    cout << "Файл products.csv успешно создан" << endl;
//}
//
//void verifyCSVFile() {
//    ifstream file("products.csv");
//
//    if (!file.is_open()) {
//        cerr << "Ошибка: не удалось открыть файл products.csv" << endl;
//        return;
//    }
//
//    string line;
//    int lineCount = 0;
//
//    while (getline(file, line)) {
//        lineCount++;
//    }
//
//    file.close();
//
//    cout << "Проверка файла:" << endl;
//    cout << "Всего строк в файле: " << lineCount << endl;
//    cout << "Записей с товарами: " << (lineCount - 1) << endl;
//
//    if (lineCount == 21) {
//        cout << "Файл содержит правильное количество записей (20 товаров + заголовок)" << endl;
//    }
//    else {
//        cout << "Внимание: количество записей не соответствует ожидаемому!" << endl;
//    }
//}
//
//int main() {
//    srand(time(0));
//
//    createCSVFile();
//    verifyCSVFile();
//
//    return 0;
//}
// Задача 8
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <iomanip>
//
//using namespace std;
//
//struct Product {
//    int id;
//    string name;
//    string category;
//    double price;
//    int quantity;
//};
//
//vector<Product> readProductsFromCSV() {
//    vector<Product> products;
//    ifstream file("products.csv");
//
//    if (!file.is_open()) {
//        cerr << "Ошибка: не удалось открыть файл products.csv" << endl;
//        return products;
//    }
//
//    string line;
//    bool firstLine = true;
//
//    while (getline(file, line)) {
//        if (firstLine) {
//            firstLine = false;
//            continue;
//        }
//
//        if (line.empty()) continue;
//
//        stringstream ss(line);
//        string token;
//        vector<string> tokens;
//
//        while (getline(ss, token, ',')) {
//            tokens.push_back(token);
//        }
//
//        if (tokens.size() >= 5) {
//            Product product;
//            product.id = stoi(tokens[0]);
//            product.name = tokens[1];
//            product.category = tokens[2];
//            product.price = stod(tokens[3]);
//            product.quantity = stoi(tokens[4]);
//
//            products.push_back(product);
//        }
//    }
//
//    file.close();
//    return products;
//}
//
//void printProducts(const vector<Product>& products) {
//    cout << "================================================================================" << endl;
//    cout << setw(4) << "ID" << setw(25) << "Название"
//        << setw(20) << "Категория"
//        << setw(12) << "Цена"
//        << setw(12) << "Количество" << endl;
//    cout << "================================================================================" << endl;
//
//    for (const auto& product : products) {
//        cout << setw(4) << product.id
//            << setw(25) << product.name
//            << setw(20) << product.category
//            << setw(12) << fixed << setprecision(2) << product.price
//            << setw(12) << product.quantity << endl;
//    }
//    cout << "================================================================================" << endl;
//}
//
//void analyzeProducts(const vector<Product>& products) {
//    if (products.empty()) {
//        cout << "Нет данных для анализа" << endl;
//        return;
//    }
//
//    int totalQuantity = 0;
//    double totalValue = 0.0;
//    double mostExpensivePrice = products[0].price;
//    double cheapestPrice = products[0].price;
//    Product mostExpensiveProduct = products[0];
//    Product cheapestProduct = products[0];
//
//    for (const auto& product : products) {
//        totalQuantity += product.quantity;
//        totalValue += product.price * product.quantity;
//
//        if (product.price > mostExpensivePrice) {
//            mostExpensivePrice = product.price;
//            mostExpensiveProduct = product;
//        }
//
//        if (product.price < cheapestPrice) {
//            cheapestPrice = product.price;
//            cheapestProduct = product;
//        }
//    }
//
//    cout << "\nСТАТИСТИКА ПО ТОВАРАМ:" << endl;
//    cout << "=======================" << endl;
//    cout << "Общее количество товаров: " << products.size() << " наименований" << endl;
//    cout << "Общее количество на складе: " << totalQuantity << " штук" << endl;
//    cout << "Суммарная стоимость всех товаров: " << fixed << setprecision(2) << totalValue << " руб." << endl;
//
//    cout << "\nСамый дорогой товар:" << endl;
//    cout << "ID: " << mostExpensiveProduct.id << ", Название: " << mostExpensiveProduct.name
//        << ", Цена: " << fixed << setprecision(2) << mostExpensiveProduct.price << " руб." << endl;
//
//    cout << "\nСамый дешевый товар:" << endl;
//    cout << "ID: " << cheapestProduct.id << ", Название: " << cheapestProduct.name
//        << ", Цена: " << fixed << setprecision(2) << cheapestProduct.price << " руб." << endl;
//}
//
//int main() {
//    vector<Product> products = readProductsFromCSV();
//
//    if (products.empty()) {
//        cout << "Файл пуст или не содержит данных" << endl;
//        return 1;
//    }
//
//    Александра Волкова, [02.12.2025 18:33]
//        cout << "СПИСОК ВСЕХ ТОВАРОВ:" << endl;
//    printProducts(products);
//
//    analyzeProducts(products);
//
//    return 0;
//}
// Задача 9
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <iomanip>
//#include <algorithm>
//
//using namespace std;
//
//struct Product {
//    int id;
//    string name;
//    string category;
//    double price;
//    int quantity;
//};
//
//vector<Product> readProductsFromCSV(const string& filename) {
//    vector<Product> products;
//    ifstream file(filename);
//
//    if (!file.is_open()) {
//        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
//        return products;
//    }
//
//    string line;
//    bool firstLine = true;
//
//    while (getline(file, line)) {
//        if (firstLine) {
//            firstLine = false;
//            continue;
//        }
//
//        if (line.empty()) continue;
//
//        stringstream ss(line);
//        string token;
//        vector<string> tokens;
//
//        while (getline(ss, token, ',')) {
//            tokens.push_back(token);
//        }
//
//        if (tokens.size() >= 5) {
//            Product product;
//            product.id = stoi(tokens[0]);
//            product.name = tokens[1];
//            product.category = tokens[2];
//            product.price = stod(tokens[3]);
//            product.quantity = stoi(tokens[4]);
//
//            products.push_back(product);
//        }
//    }
//
//    file.close();
//    return products;
//}
//
//void saveToCSV(const string& filename, const vector<Product>& products) {
//    ofstream file(filename);
//
//    if (!file.is_open()) {
//        cerr << "Ошибка: не удалось создать файл " << filename << endl;
//        return;
//    }
//
//    file << "id,name,category,price,quantity" << endl;
//
//    for (const auto& product : products) {
//        file << product.id << ",";
//        file << product.name << ",";
//        file << product.category << ",";
//        file << fixed << setprecision(2) << product.price << ",";
//        file << product.quantity << endl;
//    }
//
//    file.close();
//    cout << "Данные сохранены в файл: " << filename << endl;
//}
//
//void printFilteredProducts(const vector<Product>& products) {
//    if (products.empty()) {
//        cout << "Нет товаров, соответствующих критериям фильтрации" << endl;
//        return;
//    }
//
//    cout << "\nОТФИЛЬТРОВАННЫЕ ТОВАРЫ (" << products.size() << " шт.):" << endl;
//    cout << "======================================================================" << endl;
//    cout << setw(4) << "ID" << setw(25) << "Название"
//        << setw(15) << "Категория"
//        << setw(12) << "Цена"
//        << setw(12) << "Количество" << endl;
//    cout << "======================================================================" << endl;
//
//    for (const auto& product : products) {
//        cout << setw(4) << product.id
//            << setw(25) << product.name
//            << setw(15) << product.category
//            << setw(12) << fixed << setprecision(2) << product.price
//            << setw(12) << product.quantity << endl;
//    }
//    cout << "======================================================================" << endl;
//}
//
//void filterProducts() {
//    vector<Product> products = readProductsFromCSV("products.csv");
//
//    if (products.empty()) {
//        cout << "Файл пуст или не содержит данных" << endl;
//        return;
//    }
//
//    cout << "ВСЕГО ТОВАРОВ В БАЗЕ: " << products.size() << endl;
//    cout << "\nВЫБЕРИТЕ ТИП ФИЛЬТРАЦИИ:" << endl;
//    cout << "1. По цене (дороже указанной)" << endl;
//    cout << "2. По цене (дешевле указанной)" << endl;
//    cout << "3. По категории" << endl;
//    cout << "4. По наличию на складе (больше указанного количества)" << endl;
//    cout << "5. Комбинированный фильтр (цена + категория)" << endl;
//
//    int choice;
//    cout << "\nВведите номер фильтра: ";
//    cin >> choice;
//
//    vector<Product> filteredProducts;
//
//    switch (choice) {
//    case 1: {
//        double minPrice;
//        cout << "Введите минимальную цену: ";
//        cin >> minPrice;
//
//        auto priceFilter = [minPrice](const Product& p) {
//            return p.price > minPrice;
//            };
//
//        copy_if(products.
//
//            Александра Волкова, [02.12.2025 19:24]
//            begin(), products.end(), back_inserter(filteredProducts), priceFilter);
//
//        cout << "Найдено товаров дороже " << minPrice << " руб.: " << filteredProducts.size() << endl;
//        break;
//    }
//
//    case 2: {
//        double maxPrice;
//        cout << "Введите максимальную цену: ";
//        cin >> maxPrice;
//
//        auto priceFilter = [maxPrice](const Product& p) {
//            return p.price < maxPrice;
//            };
//
//        copy_if(products.begin(), products.end(), back_inserter(filteredProducts), priceFilter);
//
//        cout << "Найдено товаров дешевле " << maxPrice << " руб.: " << filteredProducts.size() << endl;
//        break;
//    }
//
//    case 3: {
//        string category;
//        cout << "Введите категорию (например: Электроника, Аксессуары): ";
//        cin.ignore();
//        getline(cin, category);
//
//        auto categoryFilter = [category](const Product& p) {
//            return p.category == category;
//            };
//
//        copy_if(products.begin(), products.end(), back_inserter(filteredProducts), categoryFilter);
//
//        cout << "Найдено товаров в категории '" << category << "': " << filteredProducts.size() << endl;
//        break;
//    }
//
//    case 4: {
//        int minQuantity;
//        cout << "Введите минимальное количество на складе: ";
//        cin >> minQuantity;
//
//        auto quantityFilter = [minQuantity](const Product& p) {
//            return p.quantity > minQuantity;
//            };
//
//        copy_if(products.begin(), products.end(), back_inserter(filteredProducts), quantityFilter);
//
//        cout << "Найдено товаров с количеством больше " << minQuantity << " шт.: " << filteredProducts.size() << endl;
//        break;
//    }
//
//    case 5: {
//        double minPrice;
//        string category;
//
//        cout << "Введите минимальную цену: ";
//        cin >> minPrice;
//        cout << "Введите категорию: ";
//        cin.ignore();
//        getline(cin, category);
//
//        auto combinedFilter = [minPrice, category](const Product& p) {
//            return p.price > minPrice && p.category == category;
//            };
//
//        copy_if(products.begin(), products.end(), back_inserter(filteredProducts), combinedFilter);
//
//        cout << "Найдено товаров дороже " << minPrice << " руб. в категории '"
//            << category << "': " << filteredProducts.size() << endl;
//        break;
//    }
//
//    default:
//        cout << "Неверный выбор!" << endl;
//        return;
//    }
//
//    printFilteredProducts(filteredProducts);
//    saveToCSV("filtered_products.csv", filteredProducts);
//}
//
//int main() {
//    filterProducts();
//    return 0;
//}
//Задача 10
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <iomanip>
//#include <algorithm>
//
//using namespace std;
//
//struct Product {
//    int id;
//    string name;
//    string category;
//    double price;
//    int quantity;
//};
//
//vector<Product> readProductsFromCSV(const string& filename) {
//    vector<Product> products;
//    ifstream file(filename);
//
//    if (!file.is_open()) {
//        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
//        return products;
//    }
//
//    string line;
//    bool firstLine = true;
//
//    while (getline(file, line)) {
//        if (firstLine) {
//            firstLine = false;
//            continue;
//        }
//
//        if (line.empty()) continue;
//
//        stringstream ss(line);
//        string token;
//        vector<string> tokens;
//
//        while (getline(ss, token, ',')) {
//            tokens.push_back(token);
//        }
//
//        if (tokens.size() >= 5) {
//            Product product;
//            product.id = stoi(tokens[0]);
//            product.name = tokens[1];
//            product.category = tokens[2];
//            product.price = stod(tokens[3]);
//            product.quantity = stoi(tokens[4]);
//
//            products.push_back(product);
//        }
//    }
//
//    file.close();
//    return products;
//}
//
//void saveToCSV(const string& filename, const vector<Product>& products) {
//    ofstream file(filename);
//
//    if (!file.is_open()) {
//        cerr << "Ошибка: не удалось создать файл " << filename << endl;
//        return;
//    }
//
//    file << "id,name,category,price,quantity" << endl;
//
//    for (const auto& product : products) {
//        file << product.id << ",";
//        file << product.name << ",";
//        file << product.category << ",";
//        file << fixed << setprecision(2) << product.price << ",";
//        file << product.quantity << endl;
//    }
//
//    file.close();
//    cout << "\nОтсортированные данные сохранены в файл: " << filename << endl;
//}
//
//void printProducts(const vector<Product>& products) {
//    if (products.empty()) {
//        cout << "Нет данных для отображения" << endl;
//        return;
//    }
//
//    cout << "\nОТСОРТИРОВАННЫЕ ТОВАРЫ (" << products.size() << " шт.):" << endl;
//    cout << "======================================================================" << endl;
//    cout << setw(4) << "ID" << setw(25) << "Название"
//        << setw(15) << "Категория"
//        << setw(12) << "Цена"
//        << setw(12) << "Количество" << endl;
//    cout << "======================================================================" << endl;
//
//    for (const auto& product : products) {
//        cout << setw(4) << product.id
//            << setw(25) << product.name
//            << setw(15) << product.category
//            << setw(12) << fixed << setprecision(2) << product.price
//            << setw(12) << product.quantity << endl;
//    }
//    cout << "======================================================================" << endl;
//}
//
//void sortProducts() {
//    vector<Product> products = readProductsFromCSV("products.csv");
//
//    if (products.empty()) {
//        cout << "Файл пуст или не содержит данных" << endl;
//        return;
//    }
//
//    cout << "ВСЕГО ТОВАРОВ В БАЗЕ: " << products.size() << endl;
//    cout << "\nВЫБЕРИТЕ КРИТЕРИЙ СОРТИРОВКИ:" << endl;
//    cout << "1. По цене (от дешевых к дорогим)" << endl;
//    cout << "2. По цене (от дорогих к дешевым)" << endl;
//    cout << "3. По названию (алфавитный порядок)" << endl;
//    cout << "4. По количеству (от большего к меньшему)" << endl;
//    cout << "5. По категории, затем по цене" << endl;
//
//    int choice;
//    cout << "\nВведите номер критерия сортировки: ";
//    cin >> choice;
//
//    vector<Product> originalProducts = products;
//
//    switch (choice) {
//    case 1: {
//        auto priceAsc = [](const Product& a, const Product& b) {
//            return a.price < b.price;
//            };
//        sort(products.begin(), products.end(), priceAsc);
//        cout << "\nСортировка по цене (от дешевых к дорогим)" << endl;
//
//        Александра Волкова, [02.12.2025 19:26]
//            break;
//    }
//
//    case 2: {
//        auto priceDesc = [](const Product& a, const Product& b) {
//            return a.price > b.price;
//            };
//        sort(products.begin(), products.end(), priceDesc);
//        cout << "\nСортировка по цене (от дорогих к дешевым)" << endl;
//        break;
//    }
//
//    case 3: {
//        auto nameAsc = [](const Product& a, const Product& b) {
//            return a.name < b.name;
//            };
//        sort(products.begin(), products.end(), nameAsc);
//        cout << "\nСортировка по названию (алфавитный порядок)" << endl;
//        break;
//    }
//
//    case 4: {
//        auto quantityDesc = [](const Product& a, const Product& b) {
//            return a.quantity > b.quantity;
//            };
//        sort(products.begin(), products.end(), quantityDesc);
//        cout << "\nСортировка по количеству (от большего к меньшему)" << endl;
//        break;
//    }
//
//    case 5: {
//        auto categoryThenPrice = [](const Product& a, const Product& b) {
//            if (a.category != b.category) {
//                return a.category < b.category;
//            }
//            return a.price < b.price;
//            };
//        sort(products.begin(), products.end(), categoryThenPrice);
//        cout << "\nСортировка по категории, затем по цене" << endl;
//        break;
//    }
//
//    default:
//        cout << "Неверный выбор! Сортировка не выполнена." << endl;
//        return;
//    }
//
//    printProducts(products);
//
//    cout << "\nСравнение с исходным порядком:" << endl;
//    if (products == originalProducts) {
//        cout << "Товары уже были отсортированы по выбранному критерию" << endl;
//    }
//
//    saveToCSV("sorted_products.csv", products);
//}
//
//int main() {
//    sortProducts();
//    return 0;
//}
//Задача 11
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <sstream>
//
//using namespace std;
//
//class ConfigManager {
//private:
//    string configFile;
//
//    string readFileContent() {
//        ifstream file(configFile);
//        if (!file.is_open()) {
//            return "";
//        }
//
//        stringstream buffer;
//        buffer << file.rdbuf();
//        file.close();
//        return buffer.str();
//    }
//
//    void writeFileContent(const string& content) {
//        ofstream file(configFile);
//        if (file.is_open()) {
//            file << content;
//            file.close();
//        }
//    }
//
//public:
//    ConfigManager(const string& filename = "config.json") : configFile(filename) {}
//
//    void createDefaultConfig() {
//        string config = R"({
//    "app_name": "My Application",
//    "version": "1.0.0",
//    "settings": {
//        "max_connections": 100,
//        "timeout": 30,
//        "debug_mode": true
//    },
//    "database": {
//        "host": "localhost",
//        "port": 5432,
//        "username": "admin"
//    }
//})";
//
//        writeFileContent(config);
//        cout << "Конфигурационный файл создан: " << configFile << endl;
//    }
//
//    void displayConfig() {
//        string content = readFileContent();
//        if (content.empty()) {
//            cout << "Файл конфигурации не найден или пуст" << endl;
//            return;
//        }
//
//        cout << "\nСОДЕРЖИМОЕ КОНФИГУРАЦИОННОГО ФАЙЛА:\n";
//        cout << "========================================\n";
//        cout << content << endl;
//        cout << "========================================\n";
//
//        parseAndPrintConfig(content);
//    }
//
//    void parseAndPrintConfig(const string& content) {
//        cout << "\nРАЗОБРАННЫЕ НАСТРОЙКИ:\n";
//        cout << "=====================\n";
//
//        size_t pos = content.find("\"app_name\":");
//        if (pos != string::npos) {
//            size_t start = content.find("\"", pos + 11) + 1;
//            size_t end = content.find("\"", start);
//            string appName = content.substr(start, end - start);
//            cout << "Имя приложения: " << appName << endl;
//        }
//
//        pos = content.find("\"version\":");
//        if (pos != string::npos) {
//            size_t start = content.find("\"", pos + 10) + 1;
//            size_t end = content.find("\"", start);
//            string version = content.substr(start, end - start);
//            cout << "Версия: " << version << endl;
//        }
//
//        pos = content.find("\"max_connections\":");
//        if (pos != string::npos) {
//            size_t start = content.find(":", pos) + 1;
//            size_t end = content.find(",", start);
//            string maxConn = content.substr(start, end - start);
//            cout << "Макс. соединений: " << maxConn << endl;
//        }
//
//        pos = content.find("\"timeout\":");
//        if (pos != string::npos) {
//            size_t start = content.find(":", pos) + 1;
//            size_t end = content.find(",", start);
//            string timeout = content.substr(start, end - start);
//            cout << "Таймаут: " << timeout << " сек." << endl;
//        }
//
//        pos = content.find("\"debug_mode\":");
//        if (pos != string::npos) {
//            size_t start = content.find(":", pos) + 1;
//            size_t end = content.find(",", start);
//            string debugMode = content.substr(start, end - start);
//            cout << "Режим отладки: " << debugMode << endl;
//        }
//
//        pos = content.find("\"host\":");
//        if (pos != string::npos) {
//            size_t start = content.find("\"", pos + 7) + 1;
//            size_t end = content.find("\"", start);
//            string host = content.substr(start, end - start);
//            cout << "Хост БД: " << host << endl;
//        }
//
//        pos = content.find("\"port\":");
//        if (pos != string::npos) {
//            size_t start = content.find(":", pos) + 1;
//            size_t end = content.find(",", start);
//            string port = content.substr(start, end - start);
//            cout << "Порт БД: " << port << endl;
//        }
//
//        pos = content.find("\"username\":");
//        if (pos != string::npos) {
//            size_t start = content.find("\"", pos + 11) + 1;
//            size_t end = content.find("\"", start);
//            string username = content.substr(start, end - start);
//            cout << "Пользователь БД: " << username << endl;
//        }
//    }
//
//    void updateTimeout(int newTimeout) {
//        string content = readFileContent();
//        if (content.empty()) {
//            cout << "Файл конфигурации не найден" << endl;
//            return;
//        }
//
//        size_t pos = content.find("\"timeout\":");
//        if (pos != string::npos) {
//            size_t start = content.find(":", pos) + 1;
//            size_t end = content.find(",", start);
//            if (end == string::npos) {
//                end = content.find("\n", start);
//            }
//
//            string oldTimeout = content.substr(start, end - start);
//            string newContent = content.substr(0, start) + " " + to_string(newTimeout) + content.substr(end);
//
//            writeFileContent(newContent);
//            cout << "Таймаут изменен с " << oldTimeout << " на " << newTimeout << " сек." << endl;
//        }
//        else {
//            cout << "Параметр timeout не найден в конфигурации" << endl;
//        }
//    }
//
//    void updateSetting(const string& key, const string& newValue) {
//        string content = readFileContent();
//        if (content.empty()) {
//            cout << "Файл конфигурации не найден" << endl;
//            return;
//        }
//
//        string searchKey = "\"" + key + "\":";
//        size_t pos = content.find(searchKey);
//        if (pos != string::npos) {
//            size_t start = content.find(":", pos) + 1;
//            size_t end;
//
//            if (content.find_first_of("0123456789", start) == start) {
//                end = content.find_first_not_of("0123456789", start);
//            }
//            else if (content.find("true", start) == start || content.find("false", start) == start) {
//                end = content.find_first_of(",}\n", start);
//            }
//            else {
//                start = content.find("\"", pos + searchKey.length()) + 1;
//                end = content.find("\"", start);
//                newValue.insert(0, "\"");
//                newValue.append("\"");
//            }
//
//            string oldValue = content.substr(start, end - start);
//            string newContent = content.substr(0, start) + " " + newValue + content.substr(end);
//
//            writeFileContent(newContent);
//            cout << "Параметр '" << key << "' изменен с '" << oldValue << "' на '" << newValue << "'" << endl;
//        }
//        else {
//            cout << "Параметр '" << key << "' не найден в конфигурации" << endl;
//        }
//    }
//
//    void showMenu() {
//        int choice;
//
//        do {
//            cout << "\nМЕНЮ УПРАВЛЕНИЯ КОНФИГУРАЦИЕЙ:\n";
//            cout << "1. Создать конфигурацию по умолчанию\n";
//            cout << "2. Показать конфигурацию\n";
//            cout << "3. Изменить таймаут\n";
//            cout << "4. Изменить другую настройку\n";
//            cout << "5. Выход\n";
//            cout << "Выберите действие: ";
//            cin >> choice;
//
//            switch (choice) {
//            case 1:
//                createDefaultConfig();
//                break;
//            case 2:
//                displayConfig();
//                break;
//            case 3: {
//                int newTimeout;
//                cout << "Введите новое значение таймаута: ";
//                cin >> newTimeout;
//                updateTimeout(newTimeout);
//                break;
//            }
//            case 4: {
//                string key, value;
//                cout << "Введите имя параметра: ";
//                cin >> key;
//                cout << "Введите новое значение: ";
//                cin.ignore();
//                getline(cin, value);
//                updateSetting(key, value);
//                break;
//            }
//            case 5:
//                cout << "Выход из программы" << endl;
//                break;
//            default:
//                cout << "Неверный выбор!" << endl;
//            }
//        } while (choice != 5);
//    }
//};
//
//int main() {
//    ConfigManager configManager;
//    configManager.showMenu();
//    return 0;
//}

}


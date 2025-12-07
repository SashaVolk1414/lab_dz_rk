//ОПЕРАЦИИ НАД ОЧЕРЕДЬЮ
//Задача 1
//#include <iostream>
//#include <queue>
//#include <string>
//
//using namespace std;
//
//void addToQueue(queue<string>& q, const string& person) {
//    q.push(person);
//    cout << person << " добавлен в очередь." << endl;
//}
//
//void processQueue(queue<string>& q) {
//    if (!q.empty()) {
//        cout << "Обработан: " << q.front() << endl;
//        q.pop();
//    }
//    else {
//        cout << "Очередь пуста." << endl;
//    }
//}
//
//int main() {
//    queue<string> queue;
//
//    addToQueue(queue, "Анна");
//    addToQueue(queue, "Борис");
//    addToQueue(queue, "Виктор");
//
//    processQueue(queue);
//    processQueue(queue);
//    processQueue(queue);
//    processQueue(queue);
//
//    return 0;
//}
//
//Задача 2
//#include <iostream>
//#include <queue>
//#include <string>
//
//using namespace std;
//
//void addEvent(queue<string>& eventQueue, const string& event) {
//    eventQueue.push(event);
//    cout << "Событие добавлено: " << event << endl;
//}
//
//void processEvent(queue<string>& eventQueue) {
//    if (!eventQueue.empty()) {
//        cout << "Обрабатывается событие: " << eventQueue.front() << endl;
//        eventQueue.pop();
//    }
//    else {
//        cout << "Очередь событий пуста." << endl;
//    }
//}
//
//int main() {
//    queue<string> events;
//
//    addEvent(events, "Запрос от клиента A");
//    addEvent(events, "Запрос от клиента B");
//    addEvent(events, "Системный лог");
//
//    processEvent(events);
//    processEvent(events);
//    processEvent(events);
//    processEvent(events);
//
//    return 0;
//}
//
//Задача 3
//#include <iostream>
//#include <queue>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//struct Order {
//    string customerName;
//    vector<string> items;
//};
//
//void addOrder(queue<Order>& orderQueue, const Order& newOrder) {
//    orderQueue.push(newOrder);
//    cout << "Заказ от " << newOrder.customerName << " добавлен в очередь." << endl;
//}
//
//void processOrder(queue<Order>& orderQueue) {
//    if (!orderQueue.empty()) {
//        Order current = orderQueue.front();
//        cout << "Обрабатывается заказ для " << current.customerName << endl;
//        cout << "Товары: ";
//        for (const auto& item : current.items) {
//            cout << item << " ";
//        }
//        cout << endl;
//        orderQueue.pop();
//    }
//    else {
//        cout << "Очередь заказов пуста." << endl;
//    }
//}
//
//int main() {
//    queue<Order> orders;
//
//    Order order1 = { "Иван", {"Книга", "Ручка"} };
//    Order order2 = { "Мария", {"Ноутбук", "Мышь"} };
//
//    addOrder(orders, order1);
//    addOrder(orders, order2);
//
//    processOrder(orders);
//    processOrder(orders);
//    processOrder(orders);
//
//    return 0;
//}


//ЗАДАЧИ НА СТРУКТУРЫ
//Задача 1
//#include <iostream>
//#include <vector>
//#include <string>
//#include <limits>
//
//using namespace std;
//
//struct Employee {
//    string name;
//    int age;
//    string position;
//    double salary;
//};
//
//int main() {
//    vector<Employee> employees;
//    int n;
//
//    cout << "Введите количество сотрудников: ";
//    cin >> n;
//    cin.ignore();
//
//    for (int i = 0; i < n; i++) {
//        Employee emp;
//        cout << "\nСотрудник " << i + 1 << ":\n";
//
//        cout << "Имя: ";
//        getline(cin, emp.name);
//
//        cout << "Возраст: ";
//        cin >> emp.age;
//        cin.ignore();
//
//        cout << "Должность: ";
//        getline(cin, emp.position);
//
//        cout << "Зарплата: ";
//        cin >> emp.salary;
//        cin.ignore();
//
//        employees.push_back(emp);
//    }
//
//    if (employees.empty()) {
//        cout << "\nНет сотрудников для анализа.\n";
//        return 0;
//    }
//
//    // Поиск самого молодого и старшего сотрудников
//    Employee youngest = employees[0];
//    Employee oldest = employees[0];
//    double totalSalary = 0;
//
//    for (const auto& emp : employees) {
//        if (emp.age < youngest.age) {
//            youngest = emp;
//        }
//        if (emp.age > oldest.age) {
//            oldest = emp;
//        }
//        totalSalary += emp.salary;
//    }
//
//    // Вывод результатов
//    cout << "\n=== Результаты ===\n";
//    cout << "Самый молодой сотрудник:\n";
//    cout << "Имя: " << youngest.name << "\nВозраст: " << youngest.age
//        << "\nДолжность: " << youngest.position
//        << "\nЗарплата: " << youngest.salary << endl;
//
//    cout << "\nСамый старший сотрудник:\n";
//    cout << "Имя: " << oldest.name << "\nВозраст: " << oldest.age
//        << "\nДолжность: " << oldest.position
//        << "\nЗарплата: " << oldest.salary << endl;
//
//    cout << "\nСредняя зарплата: " << totalSalary / employees.size() << endl;
//
//    return 0;
//}
//
//Задача 2
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//struct BankAccount {
//    string accountNumber;
//    string ownerName;
//    double balance;
//};
//
//vector<BankAccount> accounts;
//
//void createAccount() {
//    BankAccount acc;
//    cout << "\nСоздание нового счета:\n";
//    cout << "Номер счета: ";
//    cin >> acc.accountNumber;
//    cin.ignore();
//
//    cout << "Имя владельца: ";
//    getline(cin, acc.ownerName);
//
//    cout << "Начальный баланс: ";
//    cin >> acc.balance;
//
//    accounts.push_back(acc);
//    cout << "Счет успешно создан!\n";
//}
//
//void deposit() {
//    string accNum;
//    double amount;
//
//    cout << "\nВнесение средств:\n";
//    cout << "Введите номер счета: ";
//    cin >> accNum;
//
//    bool found = false;
//    for (auto& acc : accounts) {
//        if (acc.accountNumber == accNum) {
//            cout << "Текущий баланс: " << acc.balance << endl;
//            cout << "Сумма для внесения: ";
//            cin >> amount;
//
//            if (amount > 0) {
//                acc.balance += amount;
//                cout << "Новый баланс: " << acc.balance << endl;
//            }
//            else {
//                cout << "Некорректная сумма!\n";
//            }
//            found = true;
//            break;
//        }
//    }
//
//    if (!found) {
//        cout << "Счет не найден!\n";
//    }
//}
//
//void withdraw() {
//    string accNum;
//    double amount;
//
//    cout << "\nСнятие средств:\n";
//    cout << "Введите номер счета: ";
//    cin >> accNum;
//
//    bool found = false;
//    for (auto& acc : accounts) {
//        if (acc.accountNumber == accNum) {
//            cout << "Текущий баланс: " << acc.balance << endl;
//            cout << "Сумма для снятия: ";
//            cin >> amount;
//
//            if (amount > 0 && amount <= acc.balance) {
//                acc.balance -= amount;
//                cout << "Новый баланс: " << acc.balance << endl;
//            }
//            else {
//                cout << "Некорректная сумма или недостаточно средств!\n";
//            }
//            found = true;
//            break;
//        }
//    }
//
//    if (!found) {
//        cout << "Счет не найден!\n";
//    }
//}
//
//void showAccountInfo() {
//    string accNum;
//
//    cout << "\nИнформация о счете:\n";
//    cout << "Введите номер счета: ";
//    cin >> accNum;
//
//    bool found = false;
//    for (const auto& acc : accounts) {
//        if (acc.accountNumber == accNum) {
//            cout << "\n=== Информация о счете ===\n";
//            cout << "Номер счета: " << acc.accountNumber << endl;
//            cout << "Владелец: " << acc.ownerName << endl;
//            cout << "Баланс: " << acc.balance << endl;
//            found = true;
//            break;
//        }
//    }
//
//    if (!found) {
//        cout << "Счет не найден!\n";
//    }
//}
//
//int main() {
//    int choice;
//
//    do {
//        cout << "\n=== Банковская система ===\n";
//        cout << "1. Создать новый счет\n";
//        cout << "2. Внести средства\n";
//        cout << "3. Снять средства\n";
//        cout << "4. Показать информацию о счете\n";
//        cout << "5. Выйти\n";
//        cout << "Выберите действие: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: createAccount(); break;
//        case 2: deposit(); break;
//        case 3: withdraw(); break;
//        case 4: showAccountInfo(); break;
//        case 5: cout << "Выход из программы.\n"; break;
//        default: cout << "Неверный выбор!\n";
//        }
//    } while (choice != 5);
//
//    return 0;
//}
//
//Задача 3
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//struct Book {
//    string title;
//    string author;
//    int year;
//    string genre;
//};
//
//struct Library {
//    vector<Book> books;
//    int count;
//
//    Library() : count(0) {}
//
//    void addBook() {
//        Book newBook;
//        cout << "\nДобавление новой книги:\n";
//        cin.ignore();
//
//        cout << "Название: ";
//        getline(cin, newBook.title);
//
//        cout << "Автор: ";
//        getline(cin, newBook.author);
//
//        cout << "Год издания: ";
//        cin >> newBook.year;
//        cin.ignore();
//
//        cout << "Жанр: ";
//        getline(cin, newBook.genre);
//
//        books.push_back(newBook);
//        count++;
//        cout << "Книга добавлена успешно!\n";
//    }
//
//    void removeBook() {
//        string titleToRemove;
//        cout << "\nУдаление книги:\n";
//        cin.ignore();
//
//        cout << "Введите название книги для удаления: ";
//        getline(cin, titleToRemove);
//
//        auto it = remove_if(books.begin(), books.end(),
//            [&titleToRemove](const Book& b) {
//                return b.title == titleToRemove;
//            });
//
//        if (it != books.end()) {
//            books.erase(it, books.end());
//            count--;
//            cout << "Книга удалена успешно!\n";
//        }
//        else {
//            cout << "Книга не найдена!\n";
//        }
//    }
//
//    void searchByAuthor() {
//        string authorToFind;
//        cout << "\nПоиск книг по автору:\n";
//        cin.ignore();
//
//        cout << "Введите имя автора: ";
//        getline(cin, authorToFind);
//
//        bool found = false;
//        cout << "\n=== Найденные книги ===\n";
//        for (const auto& book : books) {
//            if (book.author == authorToFind) {
//                cout << "Название: " << book.title << endl;
//                cout << "Автор: " << book.author << endl;
//                cout << "Год: " << book.year << endl;
//                cout << "Жанр: " << book.genre << "\n\n";
//                found = true;
//            }
//        }
//
//        if (!found) {
//            cout << "Книги этого автора не найдены.\n";
//        }
//    }
//
//    void displayAllBooks() {
//        if (books.empty()) {
//            cout << "\nБиблиотека пуста.\n";
//            return;
//        }
//
//        cout << "\n=== Все книги в библиотеке ===\n";
//        for (size_t i = 0; i < books.size(); i++) {
//            cout << "Книга " << i + 1 << ":\n";
//            cout << "Название: " << books[i].title << endl;
//            cout << "Автор: " << books[i].author << endl;
//            cout << "Год издания: " << books[i].year << endl;
//            cout << "Жанр: " << books[i].genre << "\n\n";
//        }
//        cout << "Всего книг: " << count << endl;
//    }
//};
//
//int main() {
//    Library library;
//    int choice;
//
//    do {
//        cout << "\n=== Система управления библиотекой ===\n";
//        cout << "1. Добавить книгу\n";
//        cout << "2. Удалить книгу по названию\n";
//        cout << "3. Найти книги по автору\n";
//        cout << "4. Показать все книги\n";
//        cout << "5. Выйти\n";
//        cout << "Выберите действие: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: library.addBook(); break;
//        case 2: library.removeBook(); break;
//        case 3: library.searchByAuthor(); break;
//        case 4: library.displayAllBooks(); break;
//        case 5: cout << "Выход из программы.\n"; break;
//        default: cout << "Неверный выбор!\n";
//        }
//    } while (choice != 5);
//
//    return 0;
//}

//ЗАДАЧИ НА ОБЪЕДИНЕНИЯ
//Задача 1
//#include <iostream>
//#include <cctype>
//
//using namespace std;
//
//// Объединение для хранения разных типов данных
//union Variant {
//    int intValue;
//    double doubleValue;
//    char charValue;
//};
//
//int main() {
//    Variant data;
//    char choice;
//
//    cout << "=== Хранение различных типов данных ===\n\n";
//
//    do {
//        cout << "Выберите тип данных:\n";
//        cout << "i - целое число (int)\n";
//        cout << "d - число с плавающей запятой (double)\n";
//        cout << "c - символ (char)\n";
//        cout << "q - выход\n";
//        cout << "Ваш выбор: ";
//        cin >> choice;
//
//        // Преобразуем в нижний регистр для удобства
//        choice = tolower(choice);
//
//        switch (choice) {
//        case 'i': {
//            cout << "Введите целое число: ";
//            cin >> data.intValue;
//            cout << "Вы ввели целое число: " << data.intValue << "\n\n";
//            break;
//        }
//        case 'd': {
//            cout << "Введите число с плавающей запятой: ";
//            cin >> data.doubleValue;
//            cout << "Вы ввели число: " << data.doubleValue << "\n\n";
//            break;
//        }
//        case 'c': {
//            cout << "Введите символ: ";
//            cin >> data.charValue;
//            cout << "Вы ввели символ: '" << data.charValue << "'\n\n";
//            break;
//        }
//        case 'q': {
//            cout << "Выход из программы.\n";
//            break;
//        }
//        default: {
//            cout << "Неверный выбор! Попробуйте снова.\n\n";
//            break;
//        }
//        }
//
//    } while (choice != 'q');
//
//    return 0;
//}
//
//Задача 2
//#include <iostream>
//#include <cmath>
//#include <iomanip>
//
//using namespace std;
//
//// Объединение для хранения параметров фигур
//union ShapeData {
//    struct {
//        double radius;
//    } circle;
//
//    struct {
//        double length;
//        double width;
//    } rectangle;
//};
//
//// Структура для фигуры с тегом
//struct Shape {
//    int type; // 1 - круг, 2 - прямоугольник
//    ShapeData data;
//};
//
//// Константа для числа π
//const double PI = 3.141592653589793;
//
//// Функция для вычисления площади фигуры
//double calculateArea(const Shape& shape) {
//    switch (shape.type) {
//    case 1: // Круг
//        return PI * shape.data.circle.radius * shape.data.circle.radius;
//    case 2: // Прямоугольник
//        return shape.data.rectangle.length * shape.data.rectangle.width;
//    default:
//        return 0.0;
//    }
//}
//
//// Функция для вывода информации о фигуре
//void printShapeInfo(const Shape& shape) {
//    cout << "\n=== Информация о фигуре ===\n";
//
//    switch (shape.type) {
//    case 1:
//        cout << "Тип: Круг\n";
//        cout << "Радиус: " << shape.data.circle.radius << endl;
//        break;
//    case 2:
//        cout << "Тип: Прямоугольник\n";
//        cout << "Длина: " << shape.data.rectangle.length << endl;
//        cout << "Ширина: " << shape.data.rectangle.width << endl;
//        break;
//    }
//
//    cout << fixed << setprecision(2);
//    cout << "Площадь: " << calculateArea(shape) << "\n\n";
//}
//
//int main() {
//    Shape shape;
//    int choice;
//
//    cout << "=== Управление геометрическими фигурами ===\n\n";
//
//    do {
//        cout << "Выберите фигуру:\n";
//        cout << "1 - Круг\n";
//        cout << "2 - Прямоугольник\n";
//        cout << "3 - Показать информацию о текущей фигуре\n";
//        cout << "4 - Выход\n";
//        cout << "Ваш выбор: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            shape.type = 1;
//            cout << "Введите радиус круга: ";
//            cin >> shape.data.circle.radius;
//
//            if (shape.data.circle.radius <= 0) {
//                cout << "Ошибка: радиус должен быть положительным!\n";
//            }
//            else {
//                printShapeInfo(shape);
//            }
//            break;
//        }
//        case 2: {
//            shape.type = 2;
//            cout << "Введите длину прямоугольника: ";
//            cin >> shape.data.rectangle.length;
//            cout << "Введите ширину прямоугольника: ";
//            cin >> shape.data.rectangle.width;
//
//            if (shape.data.rectangle.length <= 0 || shape.data.rectangle.width <= 0) {
//                cout << "Ошибка: длина и ширина должны быть положительными!\n";
//            }
//            else {
//                printShapeInfo(shape);
//            }
//            break;
//        }
//        case 3: {
//            if (shape.type == 1 || shape.type == 2) {
//                printShapeInfo(shape);
//            }
//            else {
//                cout << "Сначала создайте фигуру!\n";
//            }
//            break;
//        }
//        case 4: {
//            cout << "Выход из программы.\n";
//            break;
//        }
//        default: {
//            cout << "Неверный выбор! Попробуйте снова.\n";
//            break;
//        }
//        }
//
//    } while (choice != 4);
//
//    return 0;
//}
//
//Задача 3
//#include <iostream>
//#include <iomanip>
//#include <string>
//
//using namespace std;
//
//// Объединение для хранения даты и времени
//union DateTimeData {
//    struct {
//        int year;
//        int month;
//        int day;
//        int hour;
//        int minute;
//        int second;
//    } components;
//
//    // Альтернативное представление - массив из 6 компонентов
//    int allComponents[6];
//};
//
//// Структура с объединением
//struct DateTime {
//    DateTimeData data;
//
//    // Метод для проверки корректности даты
//    bool isValid() const {
//        const auto& d = data.components;
//
//        if (d.year < 0  d.month < 1  d.month > 12  d.day < 1  d.day > 31 ||
//            d.hour < 0  d.hour > 23  d.minute < 0  d.minute > 59  d.second < 0 || d.second > 59) {
//            return false;
//        }
//
//        // Проверка дней в месяце (упрощенная версия)
//        if ((d.month == 4  d.month == 6  d.month == 9 || d.month == 11) && d.day > 30) {
//            return false;
//        }
//
//        // Проверка февраля (без учета високосных годов для простоты)
//        if (d.month == 2 && d.day > 28) {
//            return false;
//        }
//
//        return true;
//    }
//
//    // Метод для форматированного вывода
//    string toString() const {
//        const auto& d = data.components;
//
//        string result;
//        result = to_string(d.year) + "-" +
//            (d.month < 10 ? "0" : "") + to_string(d.month) + "-" +
//            (d.day < 10 ? "0" : "") + to_string(d.day) + " " +
//            (d.hour < 10 ? "0" : "") + to_string(d.hour) + ":" +
//            (d.minute < 10 ? "0" : "") + to_string(d.minute) + ":" +
//            (d.second < 10 ? "0" : "") + to_string(d.second);
//
//        return result;
//    }
//
//    // Метод для вывода в разных форматах
//    void printFormatted() const {
//        const auto& d = data.components;
//
//        cout << "\n=== Форматы вывода даты и времени ===\n";
//
//        // 1. Полный формат (по умолчанию)
//        cout << "1. Полный формат: " << toString() << endl;
//
//        // 2. Только дата
//        cout << "2. Только дата: "
//            << (d.day < 10 ? "0" : "") << d.day << "."
//            << (d.month < 10 ? "0" : "") << d.month << "."
//            << d.year << endl;
//
//        // 3. Только время
//        cout << "3. Только время: "
//            << (d.hour < 10 ? "0" : "") << d.hour << ":"
//            << (d.minute < 10 ? "0" : "") << d.minute << ":"
//            << (d.second < 10 ? "0" : "") << d.second << endl;
//
//        // 4. Текстовый формат месяца
//        string monthNames[] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
//                              "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
//
//        cout << "4. Текстовый формат: "
//            << d.day << " " << monthNames[d.month - 1] << " " << d.year << " года, "
//            << (d.hour < 10 ? "0" : "") << d.hour << ":"
//            << (d.minute < 10 ? "0" : "") << d.minute << endl;
//    }
//};
//
//// Функция для ввода даты и времени
//DateTime inputDateTime() {
//    DateTime dt;
//
//    cout << "\n=== Ввод даты и времени ===\n";
//
//    cout << "Введите год: ";
//    cin >> dt.data.components.year;
//
//    cout << "Введите месяц (1-12): ";
//    cin >> dt.data.components.month;
//
//    cout << "Введите день (1-31): ";
//    cin >> dt.data.components.day;
//
//    cout << "Введите час (0-23): ";
//    cin >> dt.data.components.hour;
//
//    cout << "Введите минуту (0-59): ";
//    cin >> dt.data.components.minute;
//
//    cout << "Введите секунду (0-59): ";
//    cin >> dt.data.components.second;
//
//    return dt;
//}
//
//int main() {
//    DateTime currentDateTime;
//    int choice;
//
//    cout << "=== Хранение даты и времени ===\n\n";
//
//    do {
//        cout << "\nМеню:\n";
//        cout << "1. Ввести новую дату и время\n";
//        cout << "2. Показать текущие дату и время\n";
//        cout << "3. Показать в разных форматах\n";
//        cout << "4. Проверить корректность даты\n";
//        cout << "5. Выход\n";
//        cout << "Ваш выбор: ";
//        cin >> choice;
//
//            switch (choice) {
//            case 1: {
//                currentDateTime = inputDateTime();
//                break;
//            }
//            case 2: {
//                cout << "\nТекущая дата и время: " << currentDateTime.toString() << endl;
//                break;
//            }
//            case 3: {
//                currentDateTime.printFormatted();
//                break;
//            }
//            case 4: {
//                if (currentDateTime.isValid()) {
//                    cout << "\nДата и время корректны!\n";
//                }
//                else {
//                    cout << "\nОшибка: некорректная дата или время!\n";
//                }
//                break;
//            }
//            case 5: {
//                cout << "Выход из программы.\n";
//                break;
//            }
//            default: {
//                cout << "Неверный выбор! Попробуйте снова.\n";
//                break;
//            }
//            }
//
//    } while (choice != 5);
//
//    return 0;
//}
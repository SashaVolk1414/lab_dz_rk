## Сборка и запуск проекта
Требования к окружению
- Компилятор: C++20
- База данных: PostgreSQL 12+
- Библиотеки: libpqxx 7.0+
- Операционная система: Windows/Linux/macOS

Инструкция по сборке
- Клонирование репозитория
git clone <repository-url>
cd online-store

-Создание директории сборки
mkdir build
cd build

- Генерация проектных файлов
cmake ..

- Сборка проекта
cmake --build .

Настройка базы данных

- Создание базы данных
createdb online_store3

- Выполнение SQL-скриптов
psql -d online_store3 -f sql/database_setup.sql

Запуск программы
./online_store
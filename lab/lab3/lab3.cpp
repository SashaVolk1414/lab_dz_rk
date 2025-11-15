#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <string>
#include <algorithm>
using namespace std;

struct Product {
	string name;
	int countr;
	int cost;
};
void saveFile(string& msg) {
	ofstream outFile("output2.txt", ios::app);
	if (outFile.is_open()) {
		outFile << msg << endl;
		cout << "Данные успешно записаны в файл.\n";
	}
	else {
		cout << "Не удалось открыть файл для записи.\n";
	}

	outFile.close();
}
void Show1() {
	vector<Product> products;
	ifstream file("output.txt");
	string line;

	// Пока удается считать строку из файла
	while (getline(file, line)) {
		char* cstr = new char[line.length() + 1];
		strcpy(cstr, line.c_str());
		char* word = strtok(cstr, ";");
		Product p;
		p.name = word;
		word = strtok(nullptr, ";");
		p.countr = stoi(word);
		word = strtok(nullptr, ";");
		p.cost = stoi(word);
		products.push_back(p);
		delete[] cstr;

	}
	for (auto l : products) {
		cout << l.name + " - " + to_string(l.countr) + " шт., " + to_string(l.cost) + " руб." << endl;
	}
	string msg = "выведен файл так, как записан в файле";
	saveFile(msg);
	file.close();
}

void Show3() {
	vector<Product> products;
	ifstream file("output.txt");
	string line;

	// Пока удается считать строку из файла
	while (getline(file, line)) {
		char* cstr = new char[line.length() + 1];
		strcpy(cstr, line.c_str());
		char* word = strtok(cstr, ";");
		Product p;
		p.name = word;
		word = strtok(nullptr, ";");
		p.countr = stoi(word);
		word = strtok(nullptr, ";");
		p.cost = stoi(word);
		products.push_back(p);
		delete[] cstr;

	}
	int c1;
	cout << "Введите цену, и выводятся товары, цена которых превышает данное число: ";
	cin >> c1;
	for (auto l : products) {
		if (l.cost > c1) {
			cout << l.name + " - " + to_string(l.countr) + " шт., " + to_string(l.cost) + " руб." << endl;
		}

	}
	string msg;
	saveFile(msg);
	file.close();
}

void Show2() {
	vector<Product> products;
	ifstream file("output.txt");
	string line;
	while (getline(file, line)) {
		char* cstr = new char[line.length() + 1];
		strcpy(cstr, line.c_str());
		char* word = strtok(cstr, ";");
		Product p;
		p.name = word;
		word = strtok(nullptr, ";");
		p.countr = stoi(word);
		word = strtok(nullptr, ";");
		p.cost = stoi(word);
		products.push_back(p);
		delete[] cstr;

	}
	int c = 0;
	cout << "Введите цену, и выводятся товары, цена которых не превышает данное число: ";
	cin >> c;
	for (auto l : products) {
		if (l.cost <= c) {
			cout << l.name + " - " + to_string(l.countr) + " шт., " + to_string(l.cost) + " руб." << endl;
		}

	}
	string msg = "выведены товары, цена за единицу которых не превышает введенное число";
	saveFile(msg);
	file.close();
}

void WriteVoid(vector<Product>& l) {
	ofstream outFile("output.txt");
	if (outFile.is_open()) {
		for (auto p : l) {
			outFile << p.name << ';' << p.countr << ';' << p.cost << endl;

		}
	}

	outFile.close();
}
void newfileVoid() {
	ofstream outFile("output.txt");
	if (outFile.is_open()) {
		cout << "Для завершения в название товара - пусто" << endl;

		Product p;
		while (true) {
			cout << "Укажите название: ";
			getline(cin, p.name);
			if (p.name.empty()) break;
			cout << "Укажите кол-во товара: ";
			string s;
			getline(cin, s);
			p.countr = stoi(s);
			cout << "Укажите цену товара за единицу: ";
			getline(cin, s);
			p.cost = stoi(s);
			outFile << p.name << ';' << p.countr << ';' << p.cost << endl;
			string msg = "Записан: " + p.name + " - " + to_string(p.countr) + " шт., " + to_string(p.cost) + " руб.";
			cout << msg << endl;
			saveFile(msg);
		}
	}

	outFile.close();
}

void dobavVoid() {
	cin.ignore();
	ofstream outFile("output.txt", ios::app);
	if (outFile.is_open()) {
		Product p;
		cout << "Укажите название: ";
		getline(cin, p.name);
		cout << "Укажите кол-во товара: ";
		string s;
		getline(cin, s);
		p.countr = stoi(s);
		cout << "Укажите цену товара за единицу: ";
		getline(cin, s);
		p.cost = stoi(s);
		outFile << p.name << ';' << p.countr << ';' << p.cost << endl;
		string msg = "Добавлен: " + p.name + " - " + to_string(p.countr) + " шт., " + to_string(p.cost) + " руб.";
		cout << msg << endl;
		saveFile(msg);
	}

	outFile.close();
}

vector<Product> readFile() {
	vector<Product> products;
	ifstream file("output.txt");
	string line;

	while (getline(file, line)) {
		char* cstr = new char[line.length() + 1];
		strcpy(cstr, line.c_str());
		char* word = strtok(cstr, ";");
		Product p;
		p.name = word;
		word = strtok(nullptr, ";");
		p.countr = stoi(word);
		word = strtok(nullptr, ";");
		p.cost = stoi(word);
		products.push_back(p);
		delete[] cstr;
	}
	file.close();
	return products;

}
void poiskVoid() {
	string tov;
	auto l = readFile();
	bool founds = false;
	cout << "Введите название товара, информацию о котором хотите получить: ";
	cin >> tov;
	for (auto p : l) {
		if (p.name == tov) {
			cout << p.name + " - " + to_string(p.countr) + " шт., " + to_string(p.cost) + " руб." << endl;
			founds = true;
		}
	}
	string msg;
	if (!founds) {
		cout << "Товар не найден" << endl;
		msg = "Товар " + tov + " не найден";
	}
	else {
		msg = "Товар " + tov + " найден. ";
	}
	saveFile(msg);
}
void SortVoid() {
	int vibor;
	string msg;
	auto l = readFile();
	cout << "1.Сортировка по названию товара" << endl;
	cout << "2.Сортировка по кол-ву" << endl;
	cout << "3.Сортировка по цене" << endl;
	cout << "Выберите по какому критерию вы хотите сделать сортировку: ";
	cin >> vibor;
	if (vibor == 1) {
		sort(l.begin(), l.end(), [](const Product& a, const Product& b) {return a.name < b.name; });
		msg = "Сортировка по имени";
	}
	else if (vibor == 2) {
		sort(l.begin(), l.end(), [](const Product& a, const Product& b) {return a.countr < b.countr; });
		msg = "Сортировка по кол-ву";
	}
	else if (vibor == 3) {
		sort(l.begin(), l.end(), [](const Product& a, const Product& b) {return a.cost < b.cost; });
		msg = "Сортировка по цене";
	}
	else {
		cout << "Вы ввели неверное значение" << endl;
		return;
	}
	saveFile(msg);
	WriteVoid(l);
}
void ShowVoid() {
	cout << "Выберите, как хотите вывести данные" << endl;
	int vibor;
	cout << "1. Вывести так, как записано в файле\n";
	cout << "2. Вывести товары, цена за единицу которых не превышает введенное число\n";
	cout << "3. Вывести товары, цена за единицу которых превышает введенное число\n";
	cout << "Введите ваш выбор: ";
	cin >> vibor;
	// Обработка выбора пользователя
	switch (vibor) {
	case 1:
		Show1();
		break;
	case 2:
		Show2();
		break;
	case 3:
		Show3();
		break;
	default:
		cout << "Неверный выбор. Попробуйте снова.\n";
	}

}


int main() {
	setlocale(LC_ALL, "Russian");
	int vibor;
	cout << "Добавим товары в файл" << endl;
	newfileVoid();
	do {
		cout << "----------------Меню----------------" << endl;
		cout << "1. Добавить товар\n";
		cout << "2. Поиск товара\n";
		cout << "3. Сортировка товаров\n";
		cout << "4. Вывод данных о товарах\n";
		cout << "0. Завершить программу\n";
		cout << "Введите ваш выбор: ";
		cin >> vibor;
		switch (vibor) {
		case 1:
			dobavVoid();
			break;
		case 2:
			poiskVoid();
			break;
		case 3:
			SortVoid();
			break;
		case 4:
			ShowVoid();
			break;
		case 0:
			cout << "Программа завершена.\n";
			break;
		default:
			cout << "Неверный выбор. Попробуйте снова.\n";
		}
	} while (vibor != 0);
	return 0;


	cout << "Hello World" << endl;
	return 0;
}
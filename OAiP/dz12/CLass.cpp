#include <iostream>
#include <locale>
#include <string>
using namespace std;
class Shape {
public:
    int a;
};
class Publication {
private:
    string title;
public:
    Publication() { title = " "; };
    Publication(string t) :title(t) {};
    void displayInfo() {
        cout << "Название публикации "<<title << endl;
    }
    void Gettitle(string t) {
        title = t;
    }
};
class Book: public Publication {
private:
    string name;
    string autor;
    int god;
public:
    Book(string name, string autor, int god) {
        this->name = name;
        this->god = god;
        this->autor = autor;
    }
    void displayinfo() {
        cout << "Название: " + name << endl;
        cout << "Автор: " + autor << endl;
        cout << "Год издания: " << god << endl;
    }
};
class Rectangle: public Shape {
private:
    int b;
public:
    Rectangle(int a,int b) {
        this->b = b;
        this->a = a;
    }
    int calculateArea() {
        return a * b;
    }
    int calculatePerimeter() {
        return (a + b) * 2;
    }
    void displayinfo() {
        cout << "Длина: " << a << ", " << "Ширина: " << b << ", " << "Площадь: " << a*b << ", " << "Периметр: " << (a + b) *2<< endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Book k1("Война и мир", "Толстой", 1963);
    k1.Gettitle("Классика");
    k1.displayInfo();
    k1.displayinfo();
    Rectangle f1(23, 5);
    int s = f1.calculateArea();
    int p = f1.calculatePerimeter();
    f1.displayinfo();

}


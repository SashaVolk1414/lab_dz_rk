#include <iostream>
#include <locale>
using namespace std;


//Задача  2 
bool Proverka(int f) {
    if (f < 0) {
        return false;
    }
    return true;

}
int main()
{
    setlocale(LC_ALL, "Russian");
    int f = 0;
    cout << "Введите количество машин: ";
    cin >> f;
    int res = 1,l=1;
    if (Proverka(f)) {
        while (l <= f) {
            res = res * l;
            l++;
        }
        cout << "Производительность машин на фабрике: "<<res;
    }
    else {
        cout << "Кол-во машин не может быть отрицательным числом! Введите правильно значение.";
    }

    return 0;

}

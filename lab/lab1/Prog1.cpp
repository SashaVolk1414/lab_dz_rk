#include <iostream>
#include <locale>
using namespace std;
//Задача 1 

bool Proverka(double v) {
    if(v>=0){ 
        return true;
    }
    return false;
        
}
int main()
{
    setlocale(LC_ALL, "Russian");
    double v = 0;
    cout << "Напишите вашу скорость в км/ч: ";
    cin >> v;
    if (Proverka(v)) {
        if (v < 60) {
            cout << "Скорость в пределах нормы " << endl;
        }
        else if (v >= 60 or v <= 80) {
            cout << "Вы приближаетесь к превышению скорости" << endl;
        }
        else {
            cout << "Превышение скорости!" << endl;
        }
    }
    else {
        cout << "Вы ввели неверный формат скорости! " << endl;
    }
   
    return 0;
}


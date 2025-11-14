
#include <iostream>
#include <locale>
using namespace std;

bool Proverka(int n) {
    if (n <= 0) {
        return false;
    }
    else { return true; }
}
bool Proverka2(char c) {
    string d = "eyuioaEYUIOA";
    for (int i = 0; i < size(d); i++) {
        if (d[i] == c) { return true; }
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //Задача 1
    /*int n = 0;
    cout << "Введите длину в сантиметрах: ";
    cin >> n;
    if (Proverka(n)) {
        cout << "Ответ: " << n / 100 << "м и " << n % 100 << " см" << endl;
    }
    else {
        cout << "Неверный формат ввода. Введите другое значение! ";
    }*/
    //Задача 2
    /*int a = 0, b = 0;
    cout << "Введите длину прямоульника: ";
    cin >> a;
    cout << "Введите ширину прямоульника: ";
    cin >> b;
    if (Proverka(a) and Proverka(b)) {
        cout << "Площадь прямоугольника: " << a*b<< endl;
    }
    else {
        cout << "Неверный формат ввода. Введите другое значение! ";
    }*/
    //Задача 3
    /*double a = 0, b = 0;
    cout << "Введите градусы в цельсиях: ";
    cin >> a;
    cout << "Градусы в ференгейтах: " << a*9/5+32<< endl;
    */
    //Задача 4
   /*int a = 0, b = 0;
   cout << "Введите число: ";
   cin >> a;
   if(a%2==0){cout<<"Число четное"<<endl;}
   else{cout<<"Число нечетное"<<endl;}
   */
   //Задача 5
   /*int a = 0, b = 0;
   cout << "Введите число: ";
   cin >> a;
   if(a%3==0 and a % 5 == 0){cout<<"Число делится и на 3 и на 5"<<endl;}
   else if(a % 3 == 0) { cout << "Число делится на 3" << endl; }
   else if (a % 5 == 0) { cout << "Число делится на 5" << endl; }
   else{ cout << "Число не делится ни на 3, ни на 5" << endl; }
   */
   //Задача 6
   /*int n = 0;
   cout << "Введите свой возраст: ";
   cin >> n;
   if (Proverka(n)) {
       if (n < 18) { cout << "Вам меньше 18 лет!"<<endl; }
       else if (n >= 18  and n<=60) { cout << "Вам от 18 до 60 лет!" << endl; }
       else { cout << "Вам больше 60 лет!" << endl; }
   }
   else {
       cout << "Неверный формат ввода. Введите другое значение! ";
   }*/
   //Задача 7
   /*int n = 0;
   cout << "Введите число: ";
   cin >> n;
   if (Proverka(n)) {
       for (int i = 1; i < n + 1; i++) {
           cout << i * i << endl;
       }
   }
   else {
       cout << "Неверный формат ввода. Введите другое значение! ";
   }*/
   //Задача 9
    /*int n = 0;
    cout << "Введите число: ";
    cin >> n;
    int s = 0;
    if (Proverka(n)) {
        for (int i = 1; i < n + 1; i++) {
            if (i % 2 == 0) { s = s + i; }
            else if(i%5==0){ s = s + i; }
        }
        cout << "Ответ: " << s<<endl;
    }
    else {
        cout << "Неверный формат ввода. Введите другое значение! ";
    }*/
    //Задача 10
    /*int a = 0;
    cout << "Введите число: ";
    cin >> a;
    if (a> 0) { cout << "Число положительное" << endl; }
    else if(a<0) { cout << "Число отрицательное" << endl; }
    else { cout << "Число равно 0" << endl; }
    */
    //Задача 8
    /*
    char c = ' ';
    string d;
    int s = 0;
    cout << "Введите строку: ";
    cin >> d;
    for (int i = 0; i < size(d); i++) {
        c = d[i];
        if (Proverka2(c)) { s = s + 1; }
    }
    cout << "Кол-во гласных: " << s;*/
    //Задача 11
for (int i = 32; i < 127; i++) {
    cout << "Код: " << i << " Символ: " << char(i) << endl;

    }
    return 0;

}


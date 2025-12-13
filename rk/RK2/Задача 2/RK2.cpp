#include <iostream>
#include <locale>
#include <string>
using namespace std;

class BankAccount {
protected:
    int numberch;
    string name;
    double balans;
public:
    BankAccount() {
        numberch = 000000;
        name = " ";
        balans = 0;
    }
    BankAccount(int numberch,string name,double balans) {
        this->numberch = numberch;
        this->name = name;
        this->balans = balans;
    }
    void Deposit() {
        double n;
        cout << "Введите сумму для пополнения: ";
        cin >> n;
        if (n>0) {
            balans += n;
            cout << "Успешное пополнение!" << endl;
        }
        else {
            cout << "Произошла ошибка, не удалось пополнить баланс" << endl;
        }
    }
    void Withdraw() {
        double n;
        cout << "Сколько хотите снять? Доступно средств: " << balans << endl;
        cout << "Ваша сумма: ";
        cin >> n;
        if (0< n and n <= balans) {
            balans -= n;
            cout << "Успешное снятие!" << endl;
        }
        else {
            cout << "Ошибка, вы ввели неверное число(" << endl;
        }
    }
    void Balanse() {
        cout << "Ваш баланс: " << balans << endl;
    }
};

class SavingsAccount: BankAccount {
protected:
    double stavka;
public:
    SavingsAccount() {
        stavka = 0;
    }
    SavingsAccount(double stavka) {
        this->stavka = stavka;
    }
    void Nachislenie(double n) {
        if (n > 0 and n < 100) {
            stavka = n;
            cout << "Успешное начисление процетов" << endl;
        }
        else {
            cout << "Ошибка, неправильное число для начисления процентов" << endl;
        }
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    BankAccount client1(172673,"Dronov Sergey Aleksandrovich",5700);
    int vibor=0;
    bool k = true;
    while (k) {
    cout << "Какое действие вы хотите совершить? " << endl;
    cout << "1. Увидеть баланс" << endl;
    cout << "2. Пополнить баланс" << endl;
    cout << "3. Снять деньги" << endl;
    cout << "4. Выход" << endl;
    cout << "Ваш выбор: ";
    cin >> vibor;
    switch (vibor) {
    case 1:
        client1.Balanse();
        break;
    case 2:
        client1.Deposit();
        break;
    case 3:
        client1.Withdraw();
        break;
    case 4:
        k = false;
        break;
    default:
        cout << "Ошибка, вы сделали неверный выбор! " << endl;

    }
    }

  
    
}


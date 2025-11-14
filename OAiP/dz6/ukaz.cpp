#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
struct Command {
    string name;  // название команды 
    int value;         // числовой параметр (0, если нет) 
};

void printCommands(const vector<Command>& buffer) {
    for (const auto& cmd : buffer) {
        cout << "Command: " << cmd.name << ", Value: " << cmd.value << std::endl;
    }
}
void parseCommand(const char * s, vector<Command> &buffer) {
    const char* ptr = s;
    string k1=""; string k2 = "";
    bool k=1;
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            k = 0;
        }
        if (k == 1) {
            k2 += *ptr;
        }
        if (k == 0) {
            if (isdigit(*ptr)) {
                k1 += *ptr;
            }
        }
        ptr++;
        
    }
    Command cmd;
    cmd.name = k2;
    if (k1 != "") {
        cmd.value = stoi(k1);
    }
    else { cmd.value = 0; }
    
    buffer.push_back(cmd);
}
void analyzePressure(const std::vector<double>& data, double& minVal, double& maxVal, double& avgVal) {
    const double* p = data.data();
    for (int i = 0; i < data.size(); i++) {
        avgVal += (*(p + i));
        if ((*(p + i)) < minVal) {
            minVal = (*(p + i));
        }
        if ((*(p + i)) > maxVal) {
            maxVal = (*(p + i));
        }
    }
    avgVal = avgVal / data.size();
}
int main()
{
    setlocale(LC_ALL, "Russian");
    //Задача 1
    /*
    char str[] = "Пример строки";
    char* ptr = str;
    int myStrLen = 0;
    while (*ptr != '\0') {
        myStrLen++; ptr++;
    }
    cout << "Кол-во символов " << myStrLen << endl; */
    //Задача 2
    /*
    char str[256];
    cout << "Введите строку: ";
    cin.getline(str, 256);
    char str2[256];
    char* ptr = str;
    char* ptr2 = str;
    cout << "Копия строки: ";
    while (*ptr != '\0') {
        *ptr2 = *ptr;
        cout << *ptr2;
        ptr++; ptr2++;
    }
    *ptr2 = '\0';

    cout << endl;*/
    //Задача 3
    /*
    char str1[] = "Первая часть"; 
    char str2[] = "Вторая часть";
    char str[100];
    char* ptr = str;
    char* cp = str1;
    while (*cp != '\0') {
        *ptr = *cp;
        ptr++; cp++;
    }
    cp = str2;
    while (*cp != '\0') {
        *ptr = *cp;
        ptr++; cp++;
    }
    *ptr = '\0';
    ptr = str;
    cout << "Конкатенация символьных строк: ";
    while (*ptr != '\0') {
        cout << *ptr;
        ptr++;
    }
    cout << endl;*/
    //Задача 4
    /*
    char str[] = "Пример строки";
    char* ptr = str;
    char t = 'р';
    int c = 0;
    while (*ptr != '\0') {  
        if (*ptr == t) {  
            c++;
        }
        ptr++;
    }
    cout << "Кол-во " << c << " символа " << t << " в строке" << endl;
    */
    //Задача 5
    /*
    char str[] = "Пример строки";
    char* ptr = str;
    cout << "Новая строка: ";
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            *ptr = '_';
        }
        cout << *ptr;
        ptr++;
    }
    cout << endl;*/
    //Задача 6
    /*
    char str[] = "Пример строки";
    char str2[50];
    char* ptr = str+strlen(str);
    char* ptr2 = str2;
    cout << "Новая строка: ";
    for(int i=0;i<strlen(str)+1;i++){
        *ptr2 = *ptr;
        cout << *ptr2;
        ptr--; ptr2++;
    }
    cout << endl;*/
    //Задача 7
    /*
    char str[] = "masam";
    bool k = 1;
    char* ptr = str + strlen(str)-1;
    char* ptr2 = str;
    cout << *ptr2 << endl;
    for (int i = 0; i < strlen(str); i++) {
        if (*ptr != *ptr2) {
            k = 0;
        }
        ptr--; ptr2++;
    }
    if (k == 0) {
        cout << "Строка не является палиндром";
    }
    else {
        cout << "Строка является палиндром";
    }
    cout << endl;*/
    //Задача 8
    /*
    char str1[] = "Первая часть"; 
    char str2[] = "часть";
    cout << "Поиск подстроки в строке (без strstr) " << endl;
    char* l = nullptr;
    char* ptr = str1;
    while (*ptr != '\0' and l==nullptr) {
        char* f1 = ptr;
        char* f2 = str2;
        while (*f2 != '\0' and *f1 == *f2) {
            f1++; f2++;
            
        }
        if (*f2 == '\0') {
            l = ptr;
        }
        ptr++;
    }
    if (l == nullptr) {
        cout << "Не найдено" << endl;
    }
    else {
        cout << l << endl;
    }*/
    //Задача 9
    /*
    char str[] = "Пример строки";
    char* ptr = str;
    char str2[256];
    char* ptr2 = str2;
    cout << "Новая строка: ";
    while (*ptr != '\0') {
        if (*ptr != ' ') {
            *ptr2 = *ptr; cout << *ptr2;
            ptr2++;
        }
        ptr++;
    }
    cout << endl; */
    //Задача 9
    /*
    char str1[] = "Первая часть";
    char str2[] = "Вторая часть";
    char* ptr = str1;
    char* ptr2 = str2;
    int l = 0;
    while (*ptr != '\0' and *ptr2 != '\0') {
        ptr++; ptr2++;
    }
    l = *ptr - *ptr2;
    if (l == 0) {
        cout << "строки равны" << endl;
    }
    else if (l < 0) {
        cout << "s1 < s2" << endl;
    }
    else{ cout << "s1 > s2" << endl; }*/
    //Задача 11
/*
    vector<int> s = { 1,2,3,4,5,6,0 };
    int* p = &s[0];
    int k = 0;
    while (*p != 0) {
        k += *p; p++;
    }
    cout << "Сумма элементов: " << k << endl;*/
    //Задача 12
/*
cout << "Увеличение всех элементов вектора на 10 " << endl;
    vector<int> s = { 1,2,3,4,5,6,0 };
    int* p = s.data();
    while (p != s.data()+(s.size()-1) ){
        *p=*p+10;
        cout << *p << " "; p++;
    }
    *p = *p + 10;
    cout << *p << " ";
    cout << endl;*/
    //Задача 13
    /*
    char str1[] = "TEMP:24.5;PRESS:101.3;HUM:55.2";
    char* ptr = str1;
    while (*ptr != '\0') {
        if (*ptr == ';') {
            cout << endl;
        }
        else { cout << *ptr; }
        ptr++;
    }*/
    //Задача 14
    /*
    vector<double> signal = { 2.0, 3.0, 1.0, 4.0, 3.0 };
    double s = 0;
    const double* p = signal.data();
    for (int i = 0; i < signal.size(); i++) {
        s += (*(p + i)) * (*(p + i));
    }
    double rms = sqrt(s / signal.size());
    cout << "RMS value: " << rms;*/
    //Задача 15
    /*
    vector<Command> buffer;
    parseCommand("FORWARD 10", buffer);
    parseCommand("TURN 90", buffer);
    parseCommand("STOP", buffer);
    printCommands(buffer);*/
    //Задача 16
    /*
    vector<double> data = { 101.3, 100.8, 101.9, 100.5, 102.0 };
    double minVal=100*100; double maxVal=-100*100; double avgVal=0;
    analyzePressure(data,minVal, maxVal,avgVal);
    cout << "Min pressure: " << minVal << endl;
    cout << "Max pressure: " << maxVal << endl;
    cout << "Average pressure: " << avgVal << endl;*/
    
}



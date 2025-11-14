#include <locale>
#include <iostream>
#include <cctype>
#include <cstring>

bool Proverka(char* s, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (s[i] == s[j]) {
                return false;  
            }
        }
    }
    return true;  
}
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
    //Задача 1
    /*
    char strk[100];
    cout << "Введите строку: ";
    cin.getline(strk, 100);
    char* k = strk;
    char str2[100];
    char* k2 = str2;

   
    for (int i = 0; i < strlen(strk); i++) {
        if (*k != ' ') {
            *k2 = *k;
            ++k2;
        }
        ++k;
    }
    *k2 = '\0';
    bool t = true;
    int len = strlen(str2);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str2[i] != str2[j]) {
            t = false;
            break; 
        }
    }

    if (t == true) {
        cout << "Строка " << strk << " является палиндромом" << endl;
    }
    else {
        cout << "Строка " << strk << " не является палиндромом" << endl;
    }*/
    //Задача 2
    /*
    char strk[100];
    cout << "Введите строку: ";
    cin.getline(strk, 100);
    char str2[100];
    char* k2 = str2;

    for (int i = 0; i < strlen(strk); i++) {
        if (strk[i] != ' ') {
            *k2 = strk[i];
            ++k2;
        }
    }
    *k2 = '\0';

    int c = 0; 

    for (int i = 0; i < strlen(str2); i++) {  
        bool k = true;
        for (int j = 0; j < i; j++) {
            if ( str2[i] == str2[j]) {  
                k = false;
                break;
            }
        }
        if (k) {
            c++;
        }
    }

    cout << "Кол-во уникальных символов: " << c;*/
    //Задача 3
    /*
    char strk[100];
    cout << "Введите строку: ";
    cin.getline(strk, 100);
    char* k1 = strk;
    char str2[100];
    char* k2 = str2;

    for (int i = 0; i < strlen(strk); i++) {
        if (!isdigit(*k1)) {
            *k2 = *k1;
            ++k2;
        }
        ++k1;
    }
    *k2 = '\0';
    cout << "Строка без цифр: " << str2;*/
    //Задача 4
    /*
    char str2[100];
    cout << "Введите 1 строку: ";
    cin.getline(str2, 100);
    char strk[100];
    cout << "Введите 2 строку: ";
    cin.getline(strk, 100);
    bool kr = true;
    for (int i = 0; i < strlen(strk); i++) { 
        bool k = false;
        for (int j = 0; j < strlen(str2); j++) {
            if (strk[i] == str2[j]) {  
                k = true;
                break;
            }
        }
        if (k == false) {
            cout << "Нет";
            kr = false;
            break;
        }
    }
    if (kr) {
        cout << "Да";
    }*/
    //Задача 5

    /*
    char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);
    
    int glas = 0;
    int sogl = 0;
    
    // Множество гласных букв (английский алфавит)
    const char glas_set[] = "AEIOUY";
    
    for(int i = 0; i < strlen(str); i++) {
        char c = toupper(str[i]); // приводим к верхнему регистру
        
        // Проверяем, является ли символ буквой
        if(isalpha(c)) {
            bool vglas = false;
            
            // Проверяем, является ли буква гласной
            for(int j = 0; j < strlen(glas_set); j++) {
                if(c == glas_set[j]) {
                    vglas = true;
                    break;
                }
            }
            
            if(vglas) {
                glas++;
            } else {
                sogl++;
            }
        }
    }
    
    cout << "Гласных: " << glas << endl;
    cout << "Согласных: " << sogl << endl;*/
    //Задача 6
    /*
    char text[100];
    int s;
    
    cout << "Введите строку: ";
    cin.getline(text, 100);
    
    cout << "Введите сдвиг: ";
    cin >> s;
    
    for(int i = 0; i < strlen(text); i++) {
        if(isupper(text[i])) {
            text[i] = (text[i] - 'A' + s) % 26 + 'A';
        } else if(islower(text[i])) {
            text[i] = (text[i] - 'a' + s) % 26 + 'a';
        }
    }
    
    cout << "Результат: " << text << endl;*/
    //Задача 7
/*
     char str[100];
     cout << "Введите строку: ";
    cin.getline(str, 100);
    
    int length = strlen(str);
    
    for(int i = 0; i < length; i++) {
        char c = str[i];
        int csount = 1;
        
        while(i + 1 < length && str[i + 1] == c) {
            csount++;
            i++;
        }
        
        cout << c<<"  " << csount << endl;
    }
    
    cout << endl;*/
    //Задача 8
/*
    char str[256];
    cout << "Введите строку: ";
    cin.getline(str, 256);
    
    bool n = true; 
    
    for(int i = 0; i < strlen(str); i++) {
        if(n && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            n = false;
        } else if(isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }
        
        if(str[i] == '.' or  str[i] == '!' or  str[i] == '?') {
            n = true;
        }
    }
    
    cout << str << endl;*/
    //Задача 9
/*
    char str1[100], str2[100];

    cout << "Введите первую строку: ";
    cin.getline(str1, 100);

    cout << "Введите вторую строку: ";
    cin.getline(str2, 100);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int** dp = new int* [len1 + 1];
    for (int i = 0; i <= len1; i++) {
        dp[i] = new int[len2 + 1]();
    }

    int maxs = 0;  
    int e = 0;     

    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxs) {
                    maxs = dp[i][j];
                    e = i - 1;  
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    if (maxs > 0) {
        cout << "Наибольшая общая подстрока: ";
        for (int i = e - maxs + 1; i <= e; i++) {
            cout << str1[i];
        }
        cout << endl;
        cout << "Длина: " << maxs << endl;
    }
    else {
        cout << "Общих подстрок не найдено" << endl;
    }

    for (int i = 0; i <= len1; i++) {
        delete[] dp[i];
    }
    delete[] dp;*/
    //Задача 10
/*
    char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);
    
    int s = 0;
    
    for(int i = 0; i <= strlen(str); i++) {
        if(str[i] == ' ' || str[i] == '\0') {
            reverse(str + s, str + i);
            s = i + 1;
        }
    }
    
    cout << str << endl;*/
    //Задача 11
/*
    char str[100];
    int k;
    
    cout << "Введите строку: ";
    cin.getline(str, 100);
    
    cout << "Введите k: ";
    cin >> k;
    
    int len = strlen(str);
    
    cout << "Подстроки длины " << k << " с уникальными символами:" << endl;
    
    for(int i = 0; i <= len - k; i++) {
        char s[100];
        for(int j = 0; j < k; j++) {
            s[j] = str[i + j];
        }
        s[k] = '\0'; 
        
        if(Proverka(s, k)) {
            cout << s<< endl;
        }
    }*/
    return 0;
}


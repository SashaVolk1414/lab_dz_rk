#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    char str1[1000];
    cout << "Введите строку: ";
    cin.getline(str1, 1000);
    int mas[10];
    mas[0] = -1;
    int y = 0;
    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] == ' ') {
            y++;
            if (y > 9) {
                break;
            }
            mas[y] = i;
        }

    }
    if (y != 9) {
        cout << "Вы ввели не 10 слов!! Введите ещё раз" << endl;
        return 0;
    }
    int Acount = 0;
    for (int i : mas)
    {
        if (str1[i + 1] == 'a') { Acount++; }
    }
    int Lmin = 100 * 100;
    int k = -1, t = 0;
    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] == ' ') {
            t = i;
            if ((t - k - 1) < Lmin) {
                Lmin = t - k - 1;
            }
        }
        
        k = t;
    }
    int Apcount = 0;
    for (int i = 1 + mas[9]; i < strlen(str1); i++) {
        if (str1[i] == 'a') { Apcount++; }
    }
    cout << "количество слов, начинающихся с буквы a: " << Acount << endl;
    cout << "длинa самого короткого слова: " << Lmin << endl;
    cout << "количество букв a в последнем слове данной строки: " << Apcount << endl;

    //Замена всех букв в верхнем регистре на строчные
    cout << "замена всех букв в верхнем регистре на строчные" << endl;
    for (int i = 0; i < strlen(str1); i++) {
        if (isalpha(str1[i])) {
            str1[i] = tolower(str1[i]);

        }
        cout << str1[i];
    }
    cout << endl;
    int PPcount = 0;
    for (int i = 1; i < 10; i++) {
        if (str1[mas[i - 1] + 1] == str1[mas[i] - 1]) {
            PPcount++;
        }
    }
    if (str1[mas[9]+1] == str1[strlen(str1) - 1]) {
        PPcount++;
    }
    cout << "количество слов, у которых первый и последний символы совпадают между собой : " << PPcount << endl;
    char* words[10];
    char* word = strtok(str1, " \t\n");
    int l = 0;
    while (word != nullptr && l < 10) {
        words[l] = word;
        l++;
        word = strtok(nullptr, " \t\n");
    }
    bool k8=0;
    for (int i = 0; i < 9; i++) {
        for (int j = i+1; j < 10; j++) {
            k8 = 0;
            for (int x = 0; x < strlen(words[i]); x++) {
                for (int y = 0; y < strlen(words[j]); y++) {
                    if (words[i][x] == words[j][y] && k8==0) {
                        cout << "Общий символ: " << words[i][x] << " между словами " << words[i] << " и " << words[j] << endl;
                        k8=1;
                    }
                }
            }
            if (k8 == 0) {
                cout << "Общих символов между словами " << words[i] << " и " << words[j]<<" нет" << endl;
            }
        }
    }
    return 0;
}


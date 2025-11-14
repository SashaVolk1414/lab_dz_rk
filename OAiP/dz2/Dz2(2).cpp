#include <iostream>
#include <locale>
#include <cmath>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    //Задача 1
    /*
    int n,s=0;
    cout << "Введите длину последовательности: ";
    cin >> n;
    int* arr = new int [n];
    for (int i = 0; i < n; i++) {
        cout << "Введите "<<i+1<<" элемент последовательности: ";
        cin >> arr[i];
        if (arr[i] > pow(2, i + 1)) {
            s = s + 1;
        }
    }
    cout << "Кол-во членов Ак, удовлетворяющих условию Ак>2**k: " << s << endl;*/
    //Задача 2
    /*
    int n,ch=0,maxs=-100*100;
    cout << "Введите длину последовательности: ";
    cin >> n;
    int* arr = new int [n];
    for (int i = 0; i < n; i++) {
        cout << "Введите "<<i+1<<" элемент последовательности: ";
        cin >> arr[i];
        if (arr[i]%2==0) {
            ch = ch + 1;
        }
        else {
            if (arr[i] > maxs) { maxs = arr[i]; }
        }
    }
    cout << "Кол-во четных чисел: " << ch << endl;
    cout << "Наибольшее из нечетных чисел: " <<maxs << endl;
    */
    //Задача 3
    /*
    double arr[15];
    double mins = 100 * 1000, maxs = -100 * 1000;
    int imins = 0, imaxs = 0;
    for (int i = 0; i < 15; i++) {
        cout << "Введите " << i + 1 << " элемент последовательности: ";
        cin >> arr[i];
        if (arr[i] > maxs) { maxs = arr[i]; imaxs = i; }
        if (arr[i] < mins) { mins = arr[i]; imins = i; }
    }
    cout << "Минимальный элемент последовательности: " << mins<<endl;
    cout << "Максимальный элемент последовательности: " << maxs << endl;
    swap(arr[0], arr[imins]);
    swap(arr[14], arr[imaxs]);
    cout << "Массив" << endl;
    for (int i = 0; i < 15; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;*/
    //Задача 4
    /*
    double arr[15];
    double mins = 100 * 1000, maxs = -100 * 1000;
    int imins = 0, imaxs = 0;
    for (int i = 0; i < 15; i++) {
        cout << "Введите " << i + 1 << " элемент последовательности: ";
        cin >> arr[i];
        if (arr[i] > maxs) { maxs = arr[i]; imaxs = i; }
        if (arr[i] < mins) { mins = arr[i]; imins = i; }
    }
    cout << "Минимальный элемент последовательности: " << mins<<endl;
    cout << "Максимальный элемент последовательности: " << maxs << endl;
    if (imaxs < imins) {
        cout << "Максимальный элемент массива предшествует минимальному элементу" << endl;
        cout << "Произведение минимального и максимального элементов " << mins * maxs;
    }
    else {
        cout << "Максимальный элемент массива не предшествует минимальному элементу" << endl;

    }
    */
    //Задача 5
    /*
    int arr[10];
    int mins = 100 * 1000, maxs = -100 * 1000;
    int imins = 0, imaxs = 0;
    for (int i = 0; i < 10; i++) {
        cout << "Введите " << i + 1 << " элемент последовательности: ";
        cin >> arr[i];
        if (arr[i] > maxs) { maxs = arr[i]; imaxs = i; }
        if (arr[i] < mins) { mins = arr[i]; imins = i; }
    }
    cout << "Минимальный элемент последовательности: " << mins << endl;
    cout << "Максимальный элемент последовательности: " << maxs << endl;
    if (imins == 4 and imaxs == 9) {
        cout << "Минимальный элемент массива расположен на 5 месте, а максимальный – на 10 месте " << endl;
        cout << "Среднее арифметическое максимального и минимального элементов массива: " << (mins + maxs) / 2 << endl;
    }*/
    //Задача 6
    /*
    double arr[15];
    double mins = 100 * 1000, maxs = -100 * 1000;
    int imins = 0, imaxs = 0;
    for (int i = 0; i < 15; i++) {
        cout << "Введите " << i + 1 << " элемент последовательности: ";
        cin >> arr[i];
        if (arr[i] > maxs) { maxs = arr[i]; imaxs = i; }
        if (arr[i] < mins) { mins = arr[i]; imins = i; }
    }
    cout << "Минимальный элемент последовательности: " << mins<<endl;
    cout << "Максимальный элемент последовательности: " << maxs << endl;
    if (imins == 1 and imaxs == 0) {
        cout << "Минимальный элемент массива находится на 2 месте, а максимальный на 1 месте в массиве " << endl;
        cout << "Массив" << endl;
        for (int i = 0; i < 15; i++) {
            arr[i] = arr[i] / 2;
            cout << arr[i] << " ";
        }
    }
    cout << endl;*/
    //Задача 7
    /*
    double arr[15];
    double mins = 100 * 1000, maxs = -100 * 1000;
    int imins = 0, imaxs = 0;
    for (int i = 0; i < 15; i++) {
        cout << "Введите " << i + 1 << " элемент последовательности: ";
        cin >> arr[i];
        if (arr[i] > maxs) { maxs = arr[i]; imaxs = i; }
        if (arr[i] < mins) { mins = arr[i]; imins = i; }
    }
    cout << "Минимальный элемент последовательности: " << mins<<endl;
    cout << "Максимальный элемент последовательности: " << maxs << endl;
    if (mins == 0 or maxs == 0) {
        cout << "Минимальный или максимальный элемент равен 0"<<endl;
        cout << "Массив" << endl;
        for (int i = 0; i < imins; i++) {
            arr[i] = 0;
            cout << arr[i] << " ";
        }
        for (int i = imins; i < 15; i++) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;*/
    //Задача 8
    /*
    int arr[10];
    int mins = 100 * 1000, maxs = -100 * 1000;
    int imins = 0, imaxs = 0;
    for (int i = 0; i < 10; i++) {
        cout << "Введите " << i + 1 << " элемент последовательности: ";
        cin >> arr[i];
        if (arr[i] > maxs) { maxs = arr[i]; imaxs = i; }
        if (arr[i] < mins) { mins = arr[i]; imins = i; }
    }
    cout << "Минимальный элемент последовательности: " << mins << endl;
    cout << "Максимальный элемент последовательности: " << maxs << endl;
    if (imins == 4 and imaxs == 1) {
        cout << "Максимальный элемент находится на 2 месте, а минимальный элемент на 5 месте" << endl;
        cout << "Массив" << endl;
        for (int i = 0; i < imins; i++) {
            cout << arr[i] << " ";
        }
        for (int i = imins; i < 10; i++) {
            arr[i] = maxs;
            cout << arr[i] << " ";
        }
        cout<<endl;
    }*/
}
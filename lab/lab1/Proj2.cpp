#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int arr[10];
    for (int i = 0; i < 10; i++) {
        cout << "Введите " << i + 1 << " элемент массива: ";
        cin >> arr[i];
    }
    for (int i = 0; i < 10; i++) {
        cout <<  i + 1 << " элемент массива: "<<arr[i]<<endl;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum = sum+arr[i];
    }
    cout <<"Сумма элементов массива: " << sum << endl;
    int mins = 100*100;
    for (int i = 0; i < 10; i++) {
        if (arr[i] < mins) { mins = arr[i]; }
    }
    cout << "Минимальный элемент массива: " << mins << endl;
    int b=0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[j] > arr[j + 1]) {
                b = arr[j+1];
                arr[j + 1] = arr[j];
                arr[j] = b;
            }
        }
    }
    cout << "-------Отсортированный массив-------" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << " элемент массива: " << arr[i] << endl;
    }
    return 0;
}

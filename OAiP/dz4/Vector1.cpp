#define _USE_MATH_DEFINES
#include <iostream>
#include <vector> 
#include <cmath>
#include <locale>
#include <algorithm>
#include <ctime>
#include <iterator>
#include <numeric> 
using namespace std;
void Show(vector <int> mas) {
    cout << "Вывод массива" << endl;
    for_each(mas.begin(), mas.end(), [](int x) { cout << x <<"  "; });
    cout << endl;
}
void Show2(vector <double> mas) {
    cout << "Вывод массива" << endl;
    for_each(mas.begin(), mas.end(), [](double x) { cout << x << "  "; });
    cout << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    //Задача 1
    /*
    vector<int> mas(10,1);
    for (int i = 0; i < mas.size(); i++) { mas[i] = i + 1; }
    for_each(mas.begin(), mas.end(), [](int x) { cout << "Элемент: " << x << "\n"; });
    */
    //Задача 2
    /*
    for_each(mas.begin(), mas.end(), [](int x) { 
        x = x * 2;
        cout << "Элемент: " << x << "\n"; 
   });*/
    //Задача 3
    /*
    vector<int> vec(20, 1);
    for (int i = 0; i < vec.size(); i++) {vec[i] = i + 1; }
    auto maxElement = max_element(vec.begin(), vec.end(), [](int a, int b) { return a < b; });
    Show(vec);
    */
    //Задача 4
    /*
    vector <int> vec(20, 1);
    int start = -100,end=100;
    for (int i = 0; i < vec.size(); i++) {
        vec[i] =rand() % (end - start + 1) + start;;
    }
    Show(vec);
    vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return x < 0; }), vec.end());
    Show(vec);*/
    //Задача 5
    /*
    vector <int>vec(20);
    int start = 0, end = 100;
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % (end - start + 1) + start;;
    }
    Show(vec);
    auto itMin = min_element(vec.begin(), vec.end());//возращает указатель
    auto itMax = max_element(vec.begin(), vec.end());
    int total = accumulate(vec.begin(), vec.end(), 0);//возращает значение
    cout << "Минимальный элемент " << *itMin << endl;
    cout << "Максимальный элемент " << *itMax << endl;
    total = total / vec.size();
    cout << "Среднее значение: " << total << endl;
    sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; });
    Show(vec);
    int l = floor(vec.size() / 2);
    cout << "Медиана " << vec[l] << endl;*/
    //Задача 6
    /*
    vector <int>vec(20);
    int start = 0, end = 100;
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % (end - start + 1) + start;;
    }
    Show(vec);
    auto it =find(vec.begin(), vec.end(), 7);
    if (it != vec.end())
        cout << "Элемент  найден: " << *it << " на позиции " << (it - vec.begin()) <<
        "\n";
    else
        cout << "Элемент "<<*it<<" не найден\n";
    sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; });
    cout << "Отсортированный" << endl;
    Show(vec);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    Show(vec);*/
    //Задача 7
    /*
    vector <int>vec(20);
    int start = -100, end = 100;
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % (end - start + 1) + start;;
    }
    Show(vec);
    vec.erase(remove_if(vec.begin(), vec.end(), [](int x) {
        if ((x < -50) || (x > 50)) {
            return true;
        }
        return false; }), vec.end());
    Show(vec);
    auto itMin = min_element(vec.begin(), vec.end());//возращает указатель
    auto itMax = max_element(vec.begin(), vec.end());
    int total = accumulate(vec.begin(), vec.end(), 0);//возращает значение
    cout << "Минимальный элемент " << *itMin << endl;
    cout << "Максимальный элемент " << *itMax<< endl;
    total = total / vec.size();
    cout << "Среднее значение: " << total << endl;
    sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; });
    bool p = 1;
    for_each(vec.begin(), vec.end(), [&p](int x) { if (x < -10) { p = 0; }});
    if (!p) { cout << "Не все температуры превышают -10"; }
    else{ cout << "все температуры превышают -10"; }
    */
    //Задача 8
    /*
    vector <int>vec(50);
    int start = 0, end = 180;
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % (end - start + 1) + start;;
    }
    Show(vec);
    vector <int> mas;
    for_each(vec.begin(), vec.end(), [&mas](int x) { if (x>120) { mas.push_back(x); }});
    mas.shrink_to_fit();
    cout << "Все превышения скорости больше 120: " << endl;
    Show(mas);
    int total = accumulate(vec.begin(), vec.end(), 0);//возращает значение
    total = total / vec.size();
    cout << "Средняя скорость: " << total << endl;
    bool p = 1;
    for_each(vec.begin(), vec.end(), [&p](int x) { if (x==0) { p = 0; }});
    if (!p) { cout << "Автомобиль останавливался"; }
    else { cout << "Автомобиль двигался всегда"; }
    sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; });
    cout << "10 максимальных значений скоростей: " << endl;
    for (int i = vec.size()-10; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }*/
    //Задача 9
/*
    vector <int>vec(20);
    int start = -10, end = 100;
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % (end - start + 1) + start;;
    }
    Show(vec);
    vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return x < 0; }));
    auto itMin = min_element(vec.begin(), vec.end());//возращает указатель
    auto itMax = max_element(vec.begin(), vec.end());
    int total = accumulate(vec.begin(), vec.end(), 0);//возращает значение
    cout << "Минимальная мощность " << *itMin << endl;
    cout << "Максимальная мощность " << *itMax << endl;
    total = total / vec.size();
    cout << "Среднее значение мощности: " << total << endl;
    bool p = 1;
    for_each(vec.begin(), vec.end(), [&p](int x) { if (x <10 || x>90 ) { p = 0; }});
    if (!p) { cout << "Двигатель не всегда работал в пределах от 10 до 90 кВт" << endl; }
    else { cout << "Двигатель всегда работал в пределах от 10 до 90 кВт" << endl; }
    sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; });
    Show(vec);
    int l = floor(vec.size() / 2);
    cout << "Медиана " << vec[l] << endl;*/
    //Задача 10
/*
    vector <int>vec(30);
    int start = 10, end = 100;
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % (end - start + 1) + start;;
    }
    Show(vec);
    int total = accumulate(vec.begin(), vec.end(), 0);//возращает значение
    cout << "Общее употребление за месяц: " << total << endl;
    total = total / vec.size();
    cout << "Среднее значение мощности: " << total << endl;
    auto itMin = min_element(vec.begin(), vec.end());//возращает указатель
    auto itMax = max_element(vec.begin(), vec.end());
    cout << "Минимальное потребление энергии " << *itMin<<" в день "<< (itMin - vec.begin()) << endl;
    cout << "Максимальное потребление энергии " << *itMax << " в день " << (itMax - vec.begin()) << endl;
    int y = total * 1.2;
    vector <int> mas;
    for_each(vec.begin(), vec.end(), [&mas,&y](int x) { if (x >y) { mas.push_back(x); }});
    mas.shrink_to_fit();
    cout << " <<Пиковые>> дни: "  << endl;
    Show(mas);*/
    //Задача 10
/*
    vector <double>vec(50);
    srand(time(0));
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = static_cast<double>(rand()) / RAND_MAX;
    }
    Show2(vec);
    vec.erase(remove_if(vec.begin(), vec.end(), [](double x) { return x < 0.1; }));
    auto itMax = max_element(vec.begin(), vec.end());
    double total = accumulate(vec.begin(), vec.end(), 0);//возращает значение
    cout << "Максимальное значение амплитуды " << *itMax << endl;
    total = total / vec.size();
    cout << "Среднее значение амплитуды: " << total << endl;
    bool p = 1;
    for_each(vec.begin(), vec.end(), [&p](double x) { if (x<=0.5 ) { p = 0; }});
    if (!p) { cout << "Не все значения превышают порог 0.5" << endl; }
    else { cout << "все значения превышают порог 0.5" << endl; }
    sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; });
    cout << "10 максимальных значений амплитуд: " << endl;
    for (int i = vec.size() - 10; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    */
    //Задача 12
/*
    vector <int>vec(50);
    int start = 10, end = 100;
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % (end - start + 1) + start;;
    }
    sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; });
    Show(vec);
    auto itMin = min_element(vec.begin(), vec.end());//возращает указатель
    auto itMax = max_element(vec.begin(), vec.end());
    cout << "Минимальное потребление энергии " << *itMin<< endl;
    int y = *itMax * 0.95;
    bool p = 1;
    for_each(vec.begin(), vec.end(), [&p,&y](int x) { if (x < y) { p = 0; }});
    if (!p) { cout << "падал уровень ниже 5% от максимального" << endl; }
    else { cout << "не падал уровень ниже 5% от максимального5" << endl; }
    cout << "Среднее потребление: " << vec[0] - *vec.rbegin() << endl;
    int l = floor(vec.size() / 2);
    cout << "Медиана " << vec[l] << endl; */
    //Задача 13
/*
    vector <int>vec(50);
    int start = 0, end = 15;
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % (end - start + 1) + start;;
    }
    vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return (x < 0 || x>12); }));
    int total = accumulate(vec.begin(), vec.end(), 0);//возращает значение
    total = total / vec.size();
    cout << "Среднее давление : " << total << endl;
    auto itMin = min_element(vec.begin(), vec.end());//возращает указатель
    auto itMax = max_element(vec.begin(), vec.end());
    cout << "Минимальное давление " << *itMin << endl;
    cout << "Максимальное давление " << *itMax << endl;
    cout << "Значения, превышающие 8 бар" << endl;
    for_each(vec.begin(), vec.end(), [](int x) {if (x > 8) { cout << x << " "; }});
    */
    //Задача 14
/*
        vector <int>vec(24);
        int start = 100, end = 500;
        for (int i = 0; i < vec.size(); i++) {
            vec[i] = rand() % (end - start + 1) + start;;
        }
        Show(vec);
        vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return (x < 0 || x>12); }));
        int total = accumulate(vec.begin(), vec.end(), 0);//возращает значение
        cout << "суммарное потребление : " << total << endl;
        total = total / vec.size();
        cout << "Среднее потребление : " << total << endl;auto itMax = max_element(vec.begin(), vec.end());
        cout << "Максимальное потребление " << *itMax << " в час " << (itMax - vec.begin()) << endl;
        vector<int> vec2(vec.size());
        transform(vec.begin(), vec.end(), vec2.begin(), [&total](int x) { return x-total; });
        cout << "Отклоенение каждого часа: ";
        Show(vec2);
        sort(vec.begin(), vec.end(), [](int a, int b) { return a >b; });
        cout << "топ-5  минимальных часов потребления: " << endl;
        for (int i = vec.size() - 10; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }

*/
    //Задача 15
/*
    srand(time(0));
    vector<vector<double>> temp(5, vector<double>(30));
    vector<vector<double>> pressure(5, vector<double>(100));
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << " канал температуры" << endl;
        for (int j = 0; j < 30; j++) {
            temp[i][j] = (double)rand() / (double)RAND_MAX * (100 - 0) + 0;
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << " канал давления " << endl;
            for (int j = 0; j < 100; j++) {
                pressure[i][j] = (double)rand() / (double)RAND_MAX * (10 - 0) + 0;
                cout << pressure[i][j] << " ";
            }
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        double total = accumulate(temp[i].begin(), temp[i].end(), 0);//возращает значение
        total = total / temp[i].size();
        cout << "Средняя температура "<< i+1<<" канала : " << total << endl;
    }
    for (int i = 0; i < 5; i++) {
        auto itMin = min_element(pressure[i].begin(), pressure[i].end());//возращает указатель
        auto itMax = max_element(pressure[i].begin(), pressure[i].end());
        cout << "Минимальное давление " << i + 1 << " канала : " << *itMin << endl;
        cout << "Максимальное давление " << i + 1 << " канала : " << *itMax << endl;
    }
    int Ti = 0;double Tmax = 0.0;
    for (int i = 0; i < 5; i++) {
        auto itMin = min_element(temp[i].begin(), temp[i].end());//возращает указатель
        auto itMax = max_element(temp[i].begin(), temp[i].end());
        if ((*itMax - *itMin) > Tmax) {
            Tmax = *itMax - *itMin;
            Ti = i;
        }
    }
    cout << " канал " << Ti << " с наибольшей вариацией температуры, которая равна " << Tmax << endl;
    vector<vector<double>> pressure2(5, vector<double>(100));
    for (int i = 0; i < 5; i++) {
        double itMin = *min_element(pressure[i].begin(), pressure[i].end());//возращает указатель
        double itMax = *max_element(pressure[i].begin(), pressure[i].end());
        transform(pressure[i].begin(), pressure[i].end(), pressure2[i].begin(), [&itMin,&itMax](double x) { return (x- itMin)/(itMax-itMin); });

    }
    cout << "значения давления после нормализации" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << " канал давления " << endl;
        for_each(pressure2[i].begin(), pressure2[i].end(), [](double x) { cout << x << " "; });
        cout << endl;
    }
    cout << "значения давления после нормализации, которые превышают 0.9 (пики)" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << " канал давления " << endl;
        for_each(pressure2[i].begin(), pressure2[i].end(), [](double x) { if (x > 0.9) { cout << x << " "; }});
        cout << endl;
    }
    int totali = 0; double totalMax = 0.0;
    for (int i = 0; i < 5; i++) {
        sort(temp[i].begin(), temp[i].end(), [](int a, int b) { return a < b; });
    }
    for (int i = 0; i < 5; i++) {
        double total = accumulate(temp[i].begin(), temp[i].end(), 0);//возращает значение
        total = total / temp[i].size();
        if (total > totalMax) {
            totalMax = total; totali = i;
        }
    }
    cout << "канал с максимальной средней температурой " << totali + 1 << endl;
    for_each(temp[totali].begin(), temp[totali].end(), [](double x) {  cout << x << " "; });*/
    return 0;
}

#include <iostream>
#include <locale>
#include <cstdlib>
#include <cmath>
using namespace std;
double DlinaStorona(int x1, int y1,int x2,int y2) {
    double n = 0;
    n = sqrt((x2 - x1)* (x2 - x1) + (y2 - y1)* (y2 - y1));
    return n;
}
int Orientetion(int x1, int x2, int x3, int y1, int y2, int y3) {
    int det;
    det = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    return det;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //Задача 1
    /*
    int arr[3][2];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j == 0) {
                cout << "Введите x для "<<i+1<<" вершины: ";
                cin >> arr[i][j];
            }
            if (j == 1) {
                cout << "Введите y для " << i + 1 << " вершины: ";
                cin >> arr[i][j];
            }
        }
    }
    double n;
    n=arr[0][0] * (arr[1][1] - arr[2][1]) + arr[1][0] * (arr[2][1] - arr[0][1]) + arr[2][0] * (arr[0][1] - arr[1][1]);
    cout << n << endl;
    cout << "Площадь треугольника: " << 0.5 * fabs(n);*/
    //Задача 2
    /*int** arr;
    int k = 0;
    cout << "Введите кол-во вершин многоугольника: ";
    cin >> k;
    if (k < 3) {
       cout << "Неверный ввод данных! Многоугольник - это фигура, у которой больше 2 вершин ";
    }
    else {
        arr = new int* [k];
        for (int i = 0; i < k; i++) {
            arr[i] = new int[2];
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (j == 0) {
                    cout << "Введите x для " << i + 1 << " вершины: ";
                    cin >> arr[i][j];
                }
                if (j == 1) {
                    cout << "Введите y для " << i + 1 << " вершины: ";
                    cin >> arr[i][j];
                }
            }
        }
        double s = 0;
        for (int i = 1; i < k; i++) {
            s = s + DlinaStorona(arr[i - 1][0], arr[i - 1][1], arr[i][0], arr[i][1]);
        }
        cout << "Периметр многоугольника: " << s << endl;
    }*/

    //Задача 3
    /*
    int arr[3][2];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j == 0) {
                cout << "Введите x для "<<i+1<<" вершины: ";
                cin >> arr[i][j];
            }
            if (j == 1) {
                cout << "Введите y для " << i + 1 << " вершины: ";
                cin >> arr[i][j];
            }
        }
    }
    double c1,c2;
    c1 = (arr[0][0] + arr[1][0] + arr[2][0]) / 3;
    c2 = (arr[0][1] + arr[1][1] + arr[2][1]) / 3;
    cout << "Координаты центра масс треугольника x: " << c1 << " y: " << c2<<endl;
    */
    //Задача 4
    /*
    int arr[4][2];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j == 0) {
                cout << "Введите x для "<<i+1<<" вершины: ";
                cin >> arr[i][j];
            }
            if (j == 1) {
                cout << "Введите y для " << i + 1 << " вершины: ";
                cin >> arr[i][j];
            }
        }
    }
    double c1;
    c1 = DlinaStorona(arr[0][0],arr[0][1],arr[2][0],arr[2][1]);

    cout << "Диагональ: " << c1 <<endl;*/

    //Задача 5
    /*
    int arr[3][2];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j == 0) {
                cout << "Введите x для " << i + 1 << " точки: ";
                cin >> arr[i][j];
            }
            if (j == 1) {
                cout << "Введите y для " << i + 1 << " точки: ";
                cin >> arr[i][j];
            }
        }
    }
    double p ;
    p = (arr[1][0] - arr[0][0]) * (arr[2][1] - arr[0][1]) - (arr[1][1] - arr[0][1]) * (arr[2][0] - arr[0][0]);
    if (p == 0) {
        cout << "Точки лежат на одной прямой" << endl;
    }
    else{
        cout << "Точки не лежат на одной прямой" << endl;
    }*/
    //Задача 6
    /*
    int arr[4][2];
    cout << "Введите координаты для 1 отрезка" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j == 0) {
                cout << "Введите x для "<<i+1<<" точки: ";
                cin >> arr[i][j];
            }
            if (j == 1) {
                cout << "Введите y для " << i + 1 << " точки: ";
                cin >> arr[i][j];
            }
        }
    }
    cout << "Введите координаты для 2 отрезка" << endl;
    for (int i = 2; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j == 0) {
                cout << "Введите x для " << i + 1 << " точки: ";
                cin >> arr[i][j];
            }
            if (j == 1) {
                cout << "Введите y для " << i + 1 << " точки: ";
                cin >> arr[i][j];
            }
        }
    }
    int s1 = Orientetion(arr[0][0], arr[1][0], arr[2][0], arr[0][1], arr[1][1], arr[2][1]);
    int s2 = Orientetion(arr[0][0], arr[1][0], arr[3][0], arr[0][1], arr[1][1], arr[3][1]);
    if ( s1== s2 and s1!=0) {
        cout << "Отрезки не пересекются" << endl;
    }
    if (s1 != s2 and s1 != 0 and s2!=0) {
        cout << "Отрезки  пересекются" << endl;
    }
    if ((s1 != s2 and s1 == 0) or (s1 != s2 and s2 == 0)) {
        cout << "Отрезки  пересекются" << endl;
    }
    if (s1 == s2 and s1 == 0) {
        cout << "Отрезки коллинеарны" << endl;
    }*/
    //Задача 8
    /*int arr[2][2];
    for (int i = 0; i < 2; i++) {
        cout << "Введите координаты " << i + 1 << " точки" << endl;
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                cout << "Введите x: ";
                cin >> arr[i][j];
            }
            if (j == 1) {
                cout << "Введите y: ";
                cin >> arr[i][j];
            }
        }
    }
    int dx = fabs(arr[0][0] - arr[1][0]);
    int dy = fabs(arr[0][1] - arr[1][1]);
    cout << "Длина отрезка, соединяющего точки: " << sqrt((dx * dx) + (dy * dy)) << endl;*/
    //Задача 7
    /*int** arr;
    int k = 0;
    cout << "Введите кол-во вершин многоугольника: ";
    cin >> k;
    if (k < 3) {
       cout << "Неверный ввод данных! Многоугольник - это фигура, у которой больше 2 вершин ";
    }
    else {
        arr = new int* [k];
        for (int i = 0; i < k; i++) {
            arr[i] = new int[2];
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (j == 0) {
                    cout << "Введите x для " << i + 1 << " вершины: ";
                    cin >> arr[i][j];
                }
                if (j == 1) {
                    cout << "Введите y для " << i + 1 << " вершины: ";
                    cin >> arr[i][j];
                }
            }
        }

    int x1, y1,x2,y2;
    cout << "Введите координаты точки, у которой мы определяем, где она находится относительно многоугольника" << endl;
    cout << "Введите х: ";
    cin >> x1;
    cout << "Введите y: ";
    cin >>y1;
    x2 = 100 * x1;
    y2 = 100 * y1;
    int s = 0;
    for (int i = 0; i < k-1; i++) {
        int s1 = Orientetion(arr[i][0], arr[i+1][0], x1, arr[i][1], arr[i+1][1], y1);
        int s2 = Orientetion(arr[i][0], arr[i + 1][0], x2, arr[i][1], arr[i + 1][1], y2);
        if (s1 != s2 and s1 != 0 and s2 != 0) {
            s++;
        }
        else if ((s1 != s2 and s1 == 0) or (s1 != s2 and s2 == 0)) {
            s++;
        }
    }
    cout << s << endl;
    if (s %2!=0) {
        cout << "Точка лежит внутри многоугольника" << endl;
    }
    else {
        cout << "Точка не лежит внутри многоугольника" << endl;
    }
    }*/

    //Задача 9
    /*int** arr;
    int k = 0;
    cout << "Введите кол-во вершин для 1 многоугольника: ";
    cin >> k;
    if (k < 3) {
        cout << "Неверный ввод данных! Многоугольник - это фигура, у которой больше 2 вершин ";
    }
    else {
        arr = new int* [k];
        for (int i = 0; i < k; i++) {
            arr[i] = new int[2];
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (j == 0) {
                    cout << "Введите x для " << i + 1 << " вершины: ";
                    cin >> arr[i][j];
                }
                if (j == 1) {
                    cout << "Введите y для " << i + 1 << " вершины: ";
                    cin >> arr[i][j];
                }
            }
        }
    
    int** arr2;
    int k2 = 0;
    cout << "Введите кол-во вершин для 2 многоугольника: ";
    cin >> k2;
    if (k2 < 3) {
        cout << "Неверный ввод данных! Многоугольник - это фигура, у которой больше 2 вершин ";
    }
    else {
        arr2 = new int* [k2];
        for (int i = 0; i < k2; i++) {
            arr2[i] = new int[2];
        }
        for (int i = 0; i < k2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (j == 0) {
                    cout << "Введите x для " << i + 1 << " вершины: ";
                    cin >> arr2[i][j];
                }
                if (j == 1) {
                    cout << "Введите y для " << i + 1 << " вершины: ";
                    cin >> arr2[i][j];
                }
            }
        }

        for (int i = 0; i < k - 1; i++) {
            for (int j = 0; j < k2 - 1; i++) {
                int s1 = Orientetion(arr[i][0], arr[i + 1][0], arr2[j][0], arr[i][1], arr[i + 1][1], arr2[j][1]);
                int s2 = Orientetion(arr[i][0], arr[i + 1][0], arr2[j + 1][0], arr[i][1], arr[i + 1][1], arr2[j + 1][1]);
                if (s1 != s2 and s1 != 0 and s2 != 0) {
                    cout << "Многоугольники пересекаются" << endl;
                    exit(EXIT_FAILURE);
                }
                else if ((s1 != s2 and s1 == 0) or (s1 != s2 and s2 == 0)) {
                    cout << "Многоугольники пересекаются" << endl;
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    }
    cout << "Многоугольники не пересекаются" << endl;*/
    return 0;
}

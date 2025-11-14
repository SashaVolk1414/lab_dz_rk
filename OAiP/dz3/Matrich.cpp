#define _USE_MATH_DEFINES
#include <iostream> 
#include <locale>
#include <cmath>
#include <cstdlib>
using namespace std;

int determinant(int matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])+ matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}
double det1(double m[4][4]) {
   return m[0][0] * (m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) + m[1][3] * (m[2][1] * m[3][2] - m[2][2] * m[3][1])) -
        m[0][1] * (m[1][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][2] - m[2][2] * m[3][0])) +
        m[0][2] * (m[1][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) - m[1][1] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][1] - m[2][1] * m[3][0])) -
        m[0][3] * (m[1][0] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]) - m[1][1] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]) + m[1][2] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]));
}


int main() {
    setlocale(LC_ALL, "Russian");
    //Задача 1
    /*
    int matrix[3][3];

    cout << "Введите координаты точек" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                cout << "Введите x для "<<i+1<<" точки: ";
                cin >> matrix[i][j];
            }
            if (j == 1) {
                cout << "Введите y для " << i + 1 << " точки: ";
                cin >> matrix[i][j];
            }
            if (j == 2) {
                matrix[i][j] = 1;
            }
        }
    }
    double det = (determinant(matrix))*0.5;
    cout << "Площадь треугольника: " << fabs(det) << endl;
    */
    //Задача 2
    /*
    int mat[2];
    double a;
    int matrix[2][2];
    cout << "Введите координаты точки" << endl;
    cout << "Введите x: "; cin >> mat[0];
    cout << "Введите y: "; cin >> mat[1];
    cout << "Введите угол в градусах: "; cin >> a;
    a = a * M_PI / 180.0;
    matrix[0][0] = cos(a); matrix[0][1] = sin(a); matrix[1][0] = -sin(a); matrix[0][0] = cos(a);
    double x, y;
    x = mat[0] * matrix[0][0] + mat[1] * matrix[0][1];
    y = mat[0] * matrix[1][0] + mat[1] * matrix[1][1];
    cout << "Новая точка после поворота:  (" << x << " , " << y << " )" << endl;
    */
    //Задача 3
    /*
    int matrix[3][3];

    cout << "Введите координаты точек" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                cout << "Введите x для " << i + 1 << " точки: ";
                cin >> matrix[i][j];
            }
            if (j == 1) {
                cout << "Введите y для " << i + 1 << " точки: ";
                cin >> matrix[i][j];
            }
            if (j == 2) {
                matrix[i][j] = 1;
            }
        }
    }
    double det = determinant(matrix);
    if (det == 0) {
        cout << "Точки коллинеарны " << endl;
    }
    else {
        cout << "Точки неколлинеарны, определитель равен:  "<< det<< endl;
    }
    */
    //Задача 4
    /*
    double matrix[4][4];
    double kaf[4];
    cout << "Введите координаты точек" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == 0) {
                cout << "Введите x для " << i + 1 << " точки: ";
                cin >> matrix[i][j];
            }
            if (j == 1) {
                cout << "Введите y для " << i + 1 << " точки: ";
                cin >> matrix[i][j];
            }
            if (j == 2) {
                cout << "Введите z для " << i + 1 << " точки: ";
                cin >> matrix[i][j];
            }
            if (j == 3) {
                matrix[i][j] = 1;
            }
        }
    }
    kaf[0] = -(matrix[0][0] * matrix[0][0] + matrix[0][1] * matrix[0][1] + matrix[0][2] * matrix[0][2] );
    kaf[1] = -(matrix[1][0] * matrix[1][0] + matrix[1][1] * matrix[1][1] + matrix[1][2] * matrix[1][2] );
    kaf[2] = -(matrix[2][0] * matrix[2][0] + matrix[2][1] * matrix[2][1] + matrix[2][2] * matrix[2][2] );
    kaf[3] = -(matrix[3][0] * matrix[3][0] + matrix[3][1] * matrix[3][1] + matrix[3][2] * matrix[3][2] );
    double x11, x12, x13, x14, a,b,c,d,s;
    cout << kaf[0] << " " << kaf[1] << " " << kaf[2] << " " << kaf[3] << endl;
    s = det1(matrix);
    if (s != 0) {
        x11 = matrix[0][0]; x12 = matrix[1][0]; x13 = matrix[2][0]; x14 = matrix[3][0];
        matrix[0][0] = kaf[0]; matrix[1][0] = kaf[1]; matrix[2][0] = kaf[2]; matrix[3][0] = kaf[3];
        a = det1(matrix) / s;
        matrix[0][0] = x11; matrix[1][0] = x12; matrix[2][0] = x13; matrix[3][0] = x14;
        x11 = matrix[0][1]; x12 = matrix[1][1]; x13 = matrix[2][1]; x14 = matrix[3][1];
        matrix[0][1] = kaf[0]; matrix[1][1] = kaf[1]; matrix[2][1] = kaf[2]; matrix[3][1] = kaf[3];
        b = det1(matrix) / s;
        matrix[0][1] = x11; matrix[1][1] = x12; matrix[2][1] = x13; matrix[3][1] = x14;
        x11 = matrix[0][2]; x12 = matrix[1][2]; x13 = matrix[2][2]; x14 = matrix[3][2];
        matrix[0][2] = kaf[0]; matrix[1][2] = kaf[1]; matrix[2][2] = kaf[2]; matrix[3][2] = kaf[3];
        c = det1(matrix) / s;
        matrix[0][2] = x11; matrix[1][2] = x12; matrix[2][2] = x13; matrix[3][2] = x14;
        x11 = matrix[0][3]; x12 = matrix[1][3]; x13 = matrix[2][3]; x14 = matrix[3][3];
        matrix[0][3] = kaf[0]; matrix[1][3] = kaf[1]; matrix[2][3] = kaf[2]; matrix[3][3] = kaf[3];
        d = det1(matrix) / s;
        matrix[0][3] = x11; matrix[1][3] = x12; matrix[2][3] = x13; matrix[3][3] = x14;
        double x0 = -a / 2, y0 = -b / 2, z0 = -c / 2;
        double r = sqrt(x0 * x0 + y0 * y0 + z0 * z0 - d);
        cout << "Уравнение сферы: r2=(x-x0)2+(y-y0)2+(z-z0)2" << endl << r * r << "=(x-" << x0 << ")2 + (y-" << y0 << ")2 + (z-" << z0 << ")2";
    }
    else {
        cout << "Ошибка!!! Система вырождена или имеет бесконенчо много решений!";
    }
    */

    return 0;
}

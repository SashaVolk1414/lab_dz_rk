#define _USE_MATH_DEFINES
#include <iostream> 
#include <locale>
#include <cmath>
#include <cstdlib>
#include <vector> 
using namespace std;

double det2(double m[4][4]) {
    return m[0][0] * (m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) + m[1][3] * (m[2][1] * m[3][2] - m[2][2] * m[3][1])) -
        m[0][1] * (m[1][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][2] - m[2][2] * m[3][0])) +
        m[0][2] * (m[1][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) - m[1][1] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][1] - m[2][1] * m[3][0])) -
        m[0][3] * (m[1][0] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]) - m[1][1] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]) + m[1][2] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]));
}
double det1(double matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}
double det3(double matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}
void Print(vector<vector<int> >& mas,int n) {
    cout << "Вывод матрицы: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mas[i][j]<<"  ";
        }
        cout << endl;
    }
    
}
void Print2(vector<vector<int> >& mas, int n,int m) {
    cout << "Вывод матрицы: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << mas[i][j] << "  ";
        }
        cout << endl;
    }

}
vector<vector<int> > Zad1(vector<vector<int> >& s, vector<vector<int> >& mas,int n) {
    cout << "Отражение относительно главной диагонали" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i][j] = mas[j][i];
        }
    }
    return s;
}
vector<vector<int> > Zad2(vector<vector<int> >& s, vector<vector<int> >& mas, int n) {
    cout << "Отражение относительно побочной диагонали" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i][j] = mas[n-1-j][n-1-i];
        }
    }
    return s;

}
vector<vector<int> > Zad3(vector<vector<int> >& s, vector<vector<int> >& mas, int n) {
    cout << "Отражение относительно вертикальной оси" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i][j] = mas[i][n - 1 - j];
        }
    }
    return s;

}
vector<vector<int> > Zad4(vector<vector<int> >& s, vector<vector<int> >& mas, int n) {
    cout << "Отражение относительно горизонтальной оси" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i][j] = mas[n - 1 - i][j];
        }
    }
    return s;
}
bool Sravnenie(vector<vector<int> >& s1, vector<vector<int> >& s2, int n) {
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s1[i][j] != s2[i][j]) {
                return false;
            }
        }
    }
    return true;
}
bool MagikKvadrat(vector<vector<int> >& s, int& sum1) {
    int n = s.size();
    int strsum=0,stlsum=0,digsum1=0,digsum2=0;
    for (int j = 0; j < n; j++) {
        sum1 += s[0][j];
    }
    for (int i = 1; i < n; i++) {
        strsum = 0;
        for (int j = 0; j < n; j++) {
            strsum += s[i][j];
        }
        if (strsum != sum1) {
            return false;
        }
    }
    for (int j = 0; j < n; j++) {
        stlsum = 0;
        for (int i = 0; i < n; i++) {
            stlsum += s[i][j];
        }
        if (stlsum != sum1) {
            return false;
        }
    }
    for (int i = 0; i < n; i++) {
        digsum1 += s[i][i];
    }
    if (digsum1 != sum1) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        digsum2 += s[i][n-1-i];
    }
    if (digsum2 != sum1) {
        return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    //Задача 1
    /*
    int n, k=0; vector<vector<int> > mas; vector<vector<int> > s;
    cout << "Введите размер матрицы: ";
    cin >> n;
    mas.resize(n); 
    s.resize(n);
    for (int i = 0; i < n; ++i) {
        mas[i].resize(n);
        s[i].resize(n);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            k++;
            cout << "Введите " << k << " элемент матрицы: ";
            cin >> mas[i][j];
        }
    }
    Print(mas, n);
    vector<vector<int> > s1= Zad1(s, mas, n);Print(s1, n);
    vector<vector<int> > s2 = Zad2(s, mas, n); Print(s2, n);
    vector<vector<int> > s3 = Zad3(s, mas, n); Print(s3, n);
    vector<vector<int> > s4 = Zad4(s, mas, n); Print(s4, n);
    vector<vector<vector<int>>> matr = { s1, s2, s3, s4 };
    vector<string> names = { "массив, отражённый относительно главной диагонали", "массив, отражённый относительно побочной диагонали", "массив, отражённый относительно вертикальной оси", "массив, отражённый относительно горизонтальной оси" };
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (Sravnenie(matr[i], matr[j],n)) {
                cout << names[i] << " совпадает с " << names[j] << endl;
            }
        }
    }
    */
    //Задача 2
   /*
   int k = 0,n;
   cout << "Введите размер матрицы: ";
   cin >> n;
   vector<vector<int>> mas(n, vector<int>(n));
   for (int i = 0; i < n; ++i) {
       for (int j = 0; j < n; ++j) {
           k++;
           cout << "Введите " << k << " элемент матрицы: ";
           cin >> mas[i][j];
       }
   }
   k = 0;
   if (MagikKvadrat(mas,k) ){
       cout << "YES " << k << endl;
   }
   else{ cout << "NO" << endl; }*/
    //Задача 3
    /*
    int n, m,k=0;
    cout << "Введите кол-во строк: "; cin >> n;
    cout << "Введите кол-во столбцов: "; cin >> m;
    vector<vector<int>> s(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            k++;
            cout << "Введите " << k << " элемент матрицы: ";
            cin >> s[i][j];
        }
    }
    vector<int> strMin(n, INT_MAX);    
    vector<int> strMax(n, INT_MIN);    
    vector<int> stlMin(m, INT_MAX);    
    vector<int> stlMax(m, INT_MIN);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] < strMin[i]) {
                strMin[i] = s[i][j];
            }
            if (s[i][j] > strMax[i]) {
                strMax[i] = s[i][j];
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (s[i][j] < stlMin[j]) {
                stlMin[j] = s[i][j];
            }
            if (s[i][j] > stlMax[j]) {
                stlMax[j] = s[i][j];
            }
        }
    }
    bool f = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == strMin[i] && s[i][j] == stlMax[j]) {
                cout << "B " << s[i][j] << " " << i + 1 << " " << j + 1 << endl;
                f = true;
            }
            if (s[i][j] == strMax[i] && s[i][j] == stlMin[j]) {
                cout << "A " << s[i][j] << " " << i + 1 << " " << j + 1 << endl;
                f = true;
            }
        }
    }
    if (!f) {
        cout << "NONE" << endl;
    }
    */
    //Задача 4
   /*
   int k = 0,n;
   cout << "Введите размер матрицы: ";
   cin >> n;
   vector<vector<int>> mas(n, vector<int>(n));
   int top = 0, bottom = n - 1, left = 0, right = n - 1;
   int num = 1;
   while (num <= n * n) {
       for (int j = left; j <= right; j++) {
           mas[top][j] = num;
           num++;
       }
       top++;
       for (int i = top; i <= bottom; i++) {
           mas[i][right] = num;
           num++;
       }
       right--;
       for (int j = right; j >= left; j--) {
           mas[bottom][j] = num;
           num++;
       }
       bottom--;
       for (int i = bottom; i >= top; i--) {
           mas[i][left] = num;
           num++;
       }
       left++;
   }
   Print(mas, n);
   */
    //Задача 5
/*
    int n, m,k=0;
    cout << "Введите кол-во строк: "; cin >> n;
    cout << "Введите кол-во столбцов: "; cin >> m;
    vector<vector<int>> mas(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            k++;
            cout << "Введите " << k << " элемент матрицы: ";
            cin >> mas[i][j];
        }
    }
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    Print2(mas, n, m);
    while (top <= bottom && left <= right) {
        // Вправо
        for (int j = left; j <= right; j++) {
            cout << mas[top][j] << " ";
        }
        top++;

        // Вниз
        for (int i = top; i <= bottom; i++) {
            cout << mas[i][right] << " ";
        }
        right--;

        if (top <= bottom) {
            // Влево
            for (int j = right; j >= left; j--) {
                cout << mas[bottom][j] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            // Вверх
            for (int i = bottom; i >= top; i--) {
                cout << mas[i][left] << " ";
            }
            left++;
        }
    }
    */
    //Задача 6
    /*
    double matrix[2][2] = {
        {2,3},
        {5,-1}
    };
    double kaf[2];

    kaf[0] = 13;
    kaf[1] = 9;
    double x11, x12 , x, y, s;
    s = det3(matrix);
    if (s != 0) {
        x11 = matrix[0][0]; x12 = matrix[1][0]; 
        matrix[0][0] = kaf[0]; matrix[1][0] = kaf[1]; 
        x = det3(matrix) / s;
        matrix[0][0] = x11; matrix[1][0] = x12; 
        x11 = matrix[0][1]; x12 = matrix[1][1]; 
        matrix[0][1] = kaf[0]; matrix[1][1] = kaf[1]; 
        y = det3(matrix) / s;
        matrix[0][1] = x11; matrix[1][1] = x12; 
        cout << "x=" << x << "    y=" << y <<  endl;

    }
    else {
        cout << "Ошибка!!! Система вырождена или имеет бесконенчо много решений!";
    }
    */
    //Задача 7
    /*
    double matrix[3][3] = {
        {1,1,1},
        {2,-1,3},
        {-1,4,-1}
    };
    double kaf[3];
    
    kaf[0] = 6;
    kaf[1] = 14;
    kaf[2] = 2;
    double x11, x12, x13, x,y,z,s;
    s = det1(matrix);
    if (s != 0) {
        x11 = matrix[0][0]; x12 = matrix[1][0]; x13 = matrix[2][0]; 
        matrix[0][0] = kaf[0]; matrix[1][0] = kaf[1]; matrix[2][0] = kaf[2]; 
        x = det1(matrix) / s;
        matrix[0][0] = x11; matrix[1][0] = x12; matrix[2][0] = x13;
        x11 = matrix[0][1]; x12 = matrix[1][1]; x13 = matrix[2][1];
        matrix[0][1] = kaf[0]; matrix[1][1] = kaf[1]; matrix[2][1] = kaf[2]; 
        y = det1(matrix) / s;
        matrix[0][1] = x11; matrix[1][1] = x12; matrix[2][1] = x13; 
        x11 = matrix[0][2]; x12 = matrix[1][2]; x13 = matrix[2][2]; 
        matrix[0][2] = kaf[0]; matrix[1][2] = kaf[1]; matrix[2][2] = kaf[2];
        z = det1(matrix) / s;
        matrix[0][2] = x11; matrix[1][2] = x12; matrix[2][2] = x13;
        cout << "x=" << x << "    y=" << y << "   z=" << z << endl;
     
    }
    else {
        cout << "Ошибка!!! Система вырождена или имеет бесконенчо много решений!";
    }*/
    //Задача 8
    /*
    double matrix[3][3] = {
        {3,-1,2},
        {2,4,-1},
        {1,-3,1}
    };
    double kaf[3];

    kaf[0] = 5;
    kaf[1] = 6;
    kaf[2] = 4;
    double x11, x12, x13, x, y, z, s;
    s = det1(matrix);
    if (s != 0) {
        x11 = matrix[0][0]; x12 = matrix[1][0]; x13 = matrix[2][0];
        matrix[0][0] = kaf[0]; matrix[1][0] = kaf[1]; matrix[2][0] = kaf[2];
        x = det1(matrix) / s;
        matrix[0][0] = x11; matrix[1][0] = x12; matrix[2][0] = x13;
        x11 = matrix[0][1]; x12 = matrix[1][1]; x13 = matrix[2][1];
        matrix[0][1] = kaf[0]; matrix[1][1] = kaf[1]; matrix[2][1] = kaf[2];
        y = det1(matrix) / s;
        matrix[0][1] = x11; matrix[1][1] = x12; matrix[2][1] = x13;
        x11 = matrix[0][2]; x12 = matrix[1][2]; x13 = matrix[2][2];
        matrix[0][2] = kaf[0]; matrix[1][2] = kaf[1]; matrix[2][2] = kaf[2];
        z = det1(matrix) / s;
        matrix[0][2] = x11; matrix[1][2] = x12; matrix[2][2] = x13;
        cout << "x=" << x << "    y=" << y << "   z=" << z << endl;

    }
    else {
        cout << "Ошибка!!! Система вырождена или имеет бесконенчо много решений!";
    }*/

    return 0;
}
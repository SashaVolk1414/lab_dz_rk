#include <iostream>
#include <string>
#include <locale>
#include <memory>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
void fillArray(unique_ptr<int[]>& arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i * i;
    }
}
void processA(shared_ptr<vector<int>> buf) {
    for (auto &i : *buf) {
        i += 1;
    }
}
void processB(shared_ptr<vector<int>> buf) {
    for (auto &i : *buf) {
        i *= 2;
    }
}
void ShowVec(shared_ptr<vector<int>> buf) {
    for (auto &i : *buf) {
        cout << i << " ";
    }
    cout << endl;
}
void Show(unique_ptr<double[]>& arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
void Show2(unique_ptr<int[]>& arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
unique_ptr<int[]> createArray(int n) {
    unique_ptr<int[]> mas = make_unique<int[]>(n);
    for (int i = 0; i < n; i++) {
        mas[i] = i + 1;
    }
    return mas;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    //Задача 1 и 2,3
    /*
    unique_ptr<int> ptr = make_unique<int>(10);
    cout << "Значение: " << *ptr << endl;
    *ptr = 25;
    cout << "Значение: " << *ptr << endl;
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    unique_ptr<int[]> mas= make_unique<int[]>(n);
    for (int i = 0; i < n; i++) {
        cout << "Введите "+to_string(i+1) +" элемент массива: ";
        cin >> mas[i];
    }
    cout << "Показ массива" << endl;
    for (int i = 0; i < n; i++) {
       
       cout<<mas[i]<<" ";
    }
    fillArray(mas, n);
    cout << "Показ массива 3 задание" << endl;
    for (int i = 0; i < n; i++) {

        cout << mas[i] << " ";
    }*/
    //Задача 4
    /*
    unique_ptr<int> ptr1 = make_unique<int>(42);
    unique_ptr<int> ptr2 = move(ptr1);
    if (ptr1 == nullptr) {
        cout << "ptr1 нет" << endl;
    }
    if (ptr2 != nullptr) {
        cout << "ptr2: "<<*ptr2 << endl;
    }*/
    //Задача 5
    /*
    int n,m;
    cout << "Введите размер массива: ";
    cin >> n>>m;
    unique_ptr<int[]> mas = make_unique<int[]>(n*m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mas[i * m + j] = i * j;
        }
    }
    cout << "Показ массива" << endl;
    for (int i = 0; i < n; i++) {
        cout << endl;
        for (int j = 0; j < m; j++) {
            cout << mas[i * m + j]<<" ";
        }
    }*/
    //Задача 6
    /*
    shared_ptr<int> ptr1 = make_shared<int>(10);
    shared_ptr<int> ptr2 = ptr1;
    cout << "Значение через ptr1: " << *ptr1 << endl;
    cout << "Значение через ptr2: " << *ptr2 << endl;
    cout << "Счётчик ссылок: " << ptr1.use_count() << endl;
    ptr1.reset();
    cout << "Значение через ptr2 после сброса ptr1: " << *ptr2 <<endl;
    cout << "Счётчик ссылок: " << ptr2.use_count() << endl;*/
    //Задача 7
    /*
    unique_ptr<char[]> mas = make_unique<char[]>(280);
    unique_ptr<char[]> mas2 = make_unique<char[]>(280);
    string k;
    cout << "Введите строку: ";
    cin >> k;
    int gl=0,sogl=0;
    int l = 0;
    for (int i = 0; i < size(k); i++) {
        mas[i] = k[i];
        if (isalpha(mas[i])) {
            char c = tolower(mas[i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') { gl++; mas2[l] = mas[i]; l++; }
            else { sogl++; }
        }
    }
    cout << "Кол-во согласных: " << sogl << endl;
    cout << "Кол-во гласных: " << gl << endl;
    cout << "Показ массива только с гласными буквами" << endl;
    for (int i = 0; i < gl; i++) {
        cout << mas2[i] << " ";
    }*/
    
    //Задание 8
    /*
    unique_ptr<double[]> temp = make_unique<double[]>(10);
    unique_ptr<double[]> dav = make_unique<double[]>(10);
    unique_ptr<double[]> vlag = make_unique<double[]>(10);
    for (int i = 0; i < 10; i++) {
        cout << "Введите " + to_string(i + 1) + " температуру: ";
        cin >> temp[i];
        cout << "Введите " + to_string(i + 1) + " давление: ";
        cin >> dav[i];
        cout << "Введите " + to_string(i + 1) + " влажность: ";
        cin >> vlag[i];
    }
    cout << "Показ массивов" << endl;
    cout << "--------------Температура-------------" << endl;
    Show(temp, 10); cout << endl;
    cout << "--------------Давление-------------" << endl;
    Show(dav, 10); cout << endl;
    cout << "--------------Влажность-------------" << endl;
    Show(vlag, 10); cout << endl;
    double srt=0.0, srd=0.0, srv=0.0;
    for (int i = 0; i < 10; i++) {
        srt += temp[i];
        srd += dav[i];
        srv += vlag[i];
    }
    srt = srt / 10; srv = srv / 10; srd = srd / 10;
    cout << setw(20) << "Параметр" << setw(20) << "Среднее значение" << endl;
    cout << setw(20) << "Температура" << setw(20) << srt << endl;
    cout << setw(20) << "Давление" << setw(20) << srd << endl;
    cout << setw(20) << "Влажность" << setw(20) << srv << endl;*/
    //Задача 9
    /*
    shared_ptr<vector<int>> buffer =make_shared<vector<int>>();
    for (int i = 1; i < 11; i++) {
        buffer->push_back(i);
    }
    cout << "Показ processA " << endl;
    processA(buffer);
    ShowVec(buffer);
    cout << "Показ processB " << endl;
    processB(buffer);
    ShowVec(buffer);
    return 0;*/
    //Задача 10
    /*int n;
cout << "Введите длину массива: ";
cin >> n;
auto mas = createArray(n);
cout << "Показ массива" << endl;
Show2(mas,n);*/
//Задание 11
                /*
                int n;
                cout << "Введите длину массива: ";
                cin >> n;
                double s;
                vector<double> signals;
                for (int i = 0; i < n; i++) {
                    cout << "Введите " + to_string(i + 1) + " элемент массива: ";
                    cin >> s;
                    signals.push_back(s);
                }
                unique_ptr<double[]> mas= make_unique<double[]>(n);
                for (int i = 0; i < n;i++) {
                    mas[i] = signals[i];
                }
                auto sr = [](unique_ptr<double[]>& c, int size) {
                    double sum = 0.0;
                    for (int i = 0; i < size; i++) {
                        sum += c[i];
                    }
                    return sum / size;
                    };
                auto normalz = [](unique_ptr<double[]>& c, int size, double maxv) {
                    if (maxv == 0.0) return 0;
                    for (int i = 0; i < size; i++) {
                        c[i] /= maxv;
                    }
                    };
                auto copyBack = [&signals](unique_ptr<double[]>& c, int size) {
                    for (int i = 0; i < size; i++) {
                        signals[i] = c[i];
                    }
                    };
                double average = sr(mas, n);
                cout << "Среднее значение: " << fixed << setprecision(2) << average << endl;
                double maxv = *max_element(signals.begin(), signals.end());
                normalz(mas, n, maxv);
                copyBack(mas, n);
                cout << "Нормализованные сигналы" << endl;
                for (auto i : signals) {
                    cout <<  fixed << setprecision(3) << i << endl;
                }*/
                //Задание 12
                /*
                vector<std::string> logs = {
                "INFO: Start",
                "ERROR: Disk failure",
                "WARNING: Low memory",
                "ERROR: Disk failure",
                "INFO: Stop"
                };
                shared_ptr<vector<string>> pLogs =make_shared<vector<string>>(logs);
                vector<string> errors;
                auto isEr = [](string log) {
                    return log.find("ERROR: ") != string::npos;
                    };
                copy_if(pLogs->begin(), pLogs->end(), back_inserter(errors), isEr);
                sort(errors.begin(), errors.end());
                auto last = unique(errors.begin(), errors.end());
                errors.erase(last, errors.end());
                cout << "Ошибки: " << endl;
                for (auto i : errors) {
                    cout << i << endl;
                }*/

        //Задача 13
        /*auto part1 = make_unique<string>("Sensor data:");
        auto part2 = make_unique<string>("Voltage stable.");
        auto part3 = make_unique<string>("System nominal.");


        vector<unique_ptr<string>> reportParts;
        reportParts.push_back(move(part1));
        reportParts.push_back(move(part2));
        reportParts.push_back(move(part3));


        auto concatParts = [](const vector<unique_ptr<string>>& parts) {
            string result;
            for (const auto& part : parts) {
                result += *part + "\n";
            }
            return result;
            };


        auto countWord = [](const string& text, const string& word) {
            size_t count = 0;
            size_t pos = 0;
            while ((pos = text.find(word, pos)) != string::npos) {
                count++;
                pos += word.length();
            }
            return count;
            };


        string report = concatParts(reportParts);
        int wordCount = countWord(report, "data");
        cout << "Отчёт:\n" << report << endl;
        cout << "Слово \"data\" встречается " << wordCount << " раз" << endl;*/


        //Задание 14
       /* int n, m;
        cout << "Введите размер массива: ";
        cin >> n >> m;
        unique_ptr<int[]> mas = make_unique<int[]>(n * m);
        cout << "Введите элементы матрицы" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mas[i * m + j];
            }
        }
        cout << "Показ массива" << endl;
        for (int i = 0; i < n; i++) {
            cout << endl;
            for (int j = 0; j < m; j++) {
                cout << mas[i * m + j] << " ";
            }
        }
        auto sumColumns = [&mas, n, m]() {
            vector<double> csum(m, 0.0);
            for (int j = 0; j < m; ++j) {
                for (int i = 0; i < n; ++i) {
                    csum[j] +=mas[i * m + j];
                }
            }
            return csum;
            };
        auto maxIndex = [](const vector<double>& v) {
            int ind = 0;
            double m = v[0];
            for (int j = 1; j < v.size(); j++) {
                if (v[j] > m) {
                    m = v[j];
                    ind = j;
                }
            }
            return ind;

            };
        auto sums = sumColumns();
        cout << endl;
        cout << "Суммы столбцов: [";
        for (size_t i = 0; i < sums.size(); ++i) {
           cout << sums[i];
            if (i < sums.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        int maxColIndex = maxIndex(sums);
        double maxSum = sums[maxColIndex];
        cout << endl<< "Столбец с максимальной суммой: " << (maxColIndex + 1) << " (" << maxSum << ")" << endl;*/
        
        //Задание 15
            //vector<string> routes = {
            //    "Moscow-Berlin",
            //    "Berlin-Paris",
            //    "Paris-Rome",
            //    "Rome-Moscow"
            //};


            //auto ptrRoutes = make_shared<vector<string>>(routes);
            //auto countCity = [](const shared_ptr<vector<string>>& routes, const string& city) {
            //    int count = 0;
            //    for (const auto& route : *routes) {
            //        if (route.find(city) != string::npos) {
            //            count++;
            //        }
            //    }
            //    return count;
            //    };

            //auto sortByLength = [](shared_ptr<vector<string>> routes) {
            //    // Пузырьковая сортировка по длине (по убыванию)
            //    auto& vec = *routes;
            //    for (size_t i = 0; i < vec.size(); ++i) {
            //        for (size_t j = 0; j < vec.size() - 1; ++j) {
            //            if (vec[j].length() < vec[j + 1].length()) {
            //                swap(vec[j], vec[j + 1]);
            //            }
            //        }
            //    }
            //    return routes;
            //    };

            //auto concat = [](const shared_ptr<vector<string>>& routes) {
            //    string result;
            //    for (size_t i = 0; i < routes->size(); ++i) {
            //        result += (*routes)[i];
            //        if (i != routes->size() - 1) {
            //            result += " -> ";
            //        }
            //    }
            //    return result;
            //    };

            //cout << "Количество маршрутов с \"Paris\": "
            //    << countCity(ptrRoutes, "Paris") << endl;

            //auto sortedRoutes = sortByLength(ptrRoutes);

            //cout << "Отсортированные маршруты:" << endl;
            //for (const auto& route : *sortedRoutes) {
            //    cout << route << endl;
            //}

            //cout << "\nОбщий маршрут:\n"<< concat(sortedRoutes) << endl;
            //Задание 13

}


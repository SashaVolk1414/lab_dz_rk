#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Light {
    bool isOn;
public:
    Light() : isOn(false) {}
    string getStatus() const { 
        if (isOn == true) {
            return "вкл";
        }
        else {
            return "выкл";
        }
    }
    bool getState() const { return isOn; }
    void setState(bool state) { isOn = state; }
};

class Thermostat {
    int temperature;
public:
    Thermostat() : temperature(20) {}
    void setTemperature(int temp) { temperature = temp; }
    int getTemperature() const { return temperature; }
};

class SecuritySystem {
    bool isArmed;
public:
    SecuritySystem() : isArmed(false) {}
    string getStatus()const {
        if (isArmed == true) {
            return "вкл";
        }
        else {
            return "выкл";
        }
    }
    bool getState() const { return isArmed; }
    void setState(bool state) { isArmed = state; }
};

class Curtains {
    bool isUp;
public:
    Curtains() : isUp(false) {}
    string getStatus() const {
        if (isUp == true) {
            return "подняты";
        }
        else {
            return "опущены";
        }
    }
    bool getState() const { return isUp; }
    void setState(bool state) { isUp = state; }
};

class AirConditioner {
    bool isOn;
public:
    AirConditioner() : isOn(false) {}
    string getStatus() const {
        if (isOn == true) {
            return "вкл";
        }
        else {
            return "выкл";
        }
    }
    bool getState() const { return isOn; }
    void setState(bool state) { isOn = state; }
};

class SmartHome {
    Light light;
    Thermostat thermostat;
    SecuritySystem security;
    Curtains curtains;
    AirConditioner airConditioner;
    string stateFile;

public:
    SmartHome() : stateFile("home_state.txt") {
        if (!loadState()) {
            cout << "Файл предыдущего состояния не найден. Используются настройки по умолчанию.\n";
        }
    }

    void controlLight(bool state) { light.setState(state); }
    void setTemperature(int temp) { thermostat.setTemperature(temp); }
    void controlSecurity(bool state) { security.setState(state); }
    void controlCurtains(bool state) { curtains.setState(state); }
    void controlAirConditioner(bool state) { airConditioner.setState(state); }

    void displayStatus() const {
        cout << "\n--- ТЕКУЩЕЕ СОСТОЯНИЕ-----\n";
        cout << "Освещение: " << light.getStatus() << "\n";
        cout << "Температура: " << thermostat.getTemperature() << "°C\n";
        cout << "Система безопасности: " << security.getStatus() << "\n";
        cout << "Шторы: " << curtains.getStatus() << "\n";
        cout << "Кондиционер: " << airConditioner.getStatus() << "\n";
        cout << "----------------------------\n";
    }

    bool saveState() const {
        ofstream file(stateFile);
        if (!file.is_open()) {
            cout << "Ошибка: не удалось открыть файл для записи.\n";
            return false;
        }
        file << light.getState() << endl << thermostat.getTemperature() << endl<< security.getState() << endl << curtains.getState() << endl<< airConditioner.getState() << endl;
        file.close();
        return true;
    }

    bool loadState() {
        ifstream file(stateFile);
        if (!file.is_open()) return false;

        int l, t, s, c, a;
        if (!(file >> l >> t >> s >> c >> a)) {
            cout << "Ошибка: файл состояния поврежден. Используются настройки по умолчанию.\n";
            return false;
        }
        bool l1, s1, c1, a1;
        if (l == 0) l1 = false;
        else l1 = true;
        if (s == 0) s1 = false;
        else s1 = true;
        if (c == 0) c1 = false;
        else c1 = true;
        if (a == 0) a1 = false;
        else a1 = true;
        light.setState(l1);
        thermostat.setTemperature(t);
        security.setState(s1);
        curtains.setState(c1);
        airConditioner.setState(a1);
        file.close();
        cout << "Состояние загружено из файла.\n";
        return true;
    }
};

void displayMenu() {
    cout << "\n=== СИСТЕМА УПРАВЛЕНИЯ УМНЫМ ДОМОМ ===\n";
    cout << "1. Включить освещение\n";
    cout << "2. Выключить освещение\n";
    cout << "3. Установить температуру\n";
    cout << "4. Включить систему безопасности\n";
    cout << "5. Выключить систему безопасности\n";
    cout << "6. Поднять шторы\n";
    cout << "7. Опустить шторы\n";
    cout << "8. Включить кондиционер\n";
    cout << "9. Выключить кондиционер\n";
    cout << "10.Выход\n";
    cout << "Введите ваш выбор (1-10): ";
}

int Proverka(const string& p, int min, int max) {
    int value;
    while (true) {
        cout << p;
        cin >> value;
        if (value >= min && value <= max) {
            return value;
        }
        else {
            cout << "Ошибка: значение должно быть между " << min << " и " << max << ".\n";
            cout << "Выш выбор: ";
        }
            
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SmartHome smartHome;
    int choice;

    cout << "=== ПРОГРАММА УПРАВЛЕНИЯ УМНЫМ ДОМОМ ===\n";

    do {
        smartHome.displayStatus();
        displayMenu();

        choice = Proverka("", 1, 10);

        switch (choice) {
        case 1:
            smartHome.controlLight(true);
            cout << "Освещение ВКЛЮЧЕНО" << endl;
            break;

        case 2:
            smartHome.controlLight(false);
            cout << "Освещение ВЫКЛЮЧЕНО" << endl;
            break;

        case 3: {
            int temp = Proverka("Введите температуру (*C, от -50 до 50): ", -50, 50);
            smartHome.setTemperature(temp);
            cout << "Температура установлена на " << temp << "*C." << endl;
            break;
        }
       
        case 4:
            smartHome.controlSecurity(true);
            cout << "Система безопасности АКТИВИРОВАНА" << endl;
            break;

        case 5:
            smartHome.controlSecurity(false);
            cout << "Система безопасности ДЕАКТИВИРОВАНА" << endl;
            break;

        case 6:
            smartHome.controlCurtains(true);
            cout << "Шторы ПОДНЯТЫ" << endl;
            break;

        case 7:
            smartHome.controlCurtains(false);
            cout << "Шторы ОПУЩЕНЫ" << endl;
            break;

        case 8:
            smartHome.controlAirConditioner(true);
            cout << "Кондиционер ВКЛЮЧЕН" << endl;
            break;

        case 9:
            smartHome.controlAirConditioner(false);
            cout << "Кондиционер ВЫКЛЮЧЕН" << endl;
            break;

        case 10:
            if (smartHome.saveState()) {
                cout << "Состояние сохранено в файл home_state.txt. Выход." << endl;
            }
            else {
                cout << "Ошибка сохранения состояния. Выход." << endl;
            }
            break;

        default:
            cout << "Неверный выбор!"<<endl;
            break;
        }

    } while (choice != 10);

    return 0;
}



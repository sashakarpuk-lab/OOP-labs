#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

double getValidNumber(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < 0) {
            cout << "? Помилка: введіть додатне число!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}


class Computer {
protected:
    string* model;
    double* price;

public:
    Computer(string m = "Невідомо", double p = 0.0) {
        model = new string(m);
        price = new double(p);
    }

    virtual void Input() {
        cout << "Введіть модель: ";
        cin.ignore();
        getline(cin, *model);
        *price = getValidNumber("Введіть ціну (грн): ");
    }

    virtual void ShowInfo(ostream& out) const {
        out << "Модель комп'ютера: " << *model << endl;
        out << "Ціна: " << *price << " грн" << endl;
    }

    virtual ~Computer() {
        delete model;
        delete price;
    }
};


class Processor : public Computer {
private:
    string* brand;
    double* frequency; 

public:
    Processor(string m = "", double p = 0.0, string b = "", double f = 0.0)
        : Computer(m, p) {
        brand = new string(b);
        frequency = new double(f);
    }

    void Input() override {
        Computer::Input();
        cout << "Введіть марку процесора: ";
        getline(cin, *brand);
        *frequency = getValidNumber("Введіть тактову частоту (ГГц): ");
    }

    void ShowInfo(ostream& out) const override {
        out << "--- Процесор ---" << endl;
        Computer::ShowInfo(out);
        out << "Марка: " << *brand << endl;
        out << "Тактова частота: " << *frequency << " ГГц" << endl;
        out << endl;
    }

    ~Processor() override {
        delete brand;
        delete frequency;
    }
};


class HardDisk : public Computer {
private:
    double* capacity; 

public:
    HardDisk(string m = "", double p = 0.0, double c = 0.0)
        : Computer(m, p) {
        capacity = new double(c);
    }

    void Input() override {
        Computer::Input();
        *capacity = getValidNumber("Введіть обсяг диска (ГБ): ");
    }

    void ShowInfo(ostream& out) const override {
        out << "--- Жорсткий диск ---" << endl;
        Computer::ShowInfo(out);
        out << "Обсяг: " << *capacity << " ГБ" << endl;
        out << endl;
    }

    ~HardDisk() override {
        delete capacity;
    }
};


int main() {
    setlocale(LC_ALL, "Ukr");
    vector<Computer*> computers;
    int choice;

    do {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1. Додати процесор\n";
        cout << "2. Додати жорсткий диск\n";
        cout << "3. Показати всю інформацію\n";
        cout << "4. Записати у файл\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "? Помилка: введіть число від 0 до 4!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            Processor* p = new Processor();
            p->Input();
            computers.push_back(p);
            break;
        }
        case 2: {
            HardDisk* h = new HardDisk();
            h->Input();
            computers.push_back(h);
            break;
        }
        case 3: {
            cout << "\n===== ВВЕДЕНІ ПРИСТРОЇ =====\n";
            if (computers.empty()) {
                cout << "Немає збережених даних.\n";
            }
            else {
                for (auto comp : computers)
                    comp->ShowInfo(cout);
            }
            break;
        }
        case 4: {
            ofstream fout("computers.txt");
            if (!fout.is_open()) {
                cerr << "Помилка відкриття файлу!\n";
                break;
            }
            for (auto comp : computers)
                comp->ShowInfo(fout);
            fout.close();
            cout << "Інформацію записано у файл computers.txt\n";
            break;
        }
        case 0:
            cout << "Вихід з програми...\n";
            break;

        default:
            cout << " Невірний вибір!\n";
        }

    } while (choice != 0);

    for (auto comp : computers)
        delete comp;

    return 0;
}




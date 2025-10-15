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
            cout << "? �������: ������ ������� �����!\n";
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
    Computer(string m = "�������", double p = 0.0) {
        model = new string(m);
        price = new double(p);
    }

    virtual void Input() {
        cout << "������ ������: ";
        cin.ignore();
        getline(cin, *model);
        *price = getValidNumber("������ ���� (���): ");
    }

    virtual void ShowInfo(ostream& out) const {
        out << "������ ����'�����: " << *model << endl;
        out << "ֳ��: " << *price << " ���" << endl;
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
        cout << "������ ����� ���������: ";
        getline(cin, *brand);
        *frequency = getValidNumber("������ ������� ������� (���): ");
    }

    void ShowInfo(ostream& out) const override {
        out << "--- �������� ---" << endl;
        Computer::ShowInfo(out);
        out << "�����: " << *brand << endl;
        out << "������� �������: " << *frequency << " ���" << endl;
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
        *capacity = getValidNumber("������ ����� ����� (��): ");
    }

    void ShowInfo(ostream& out) const override {
        out << "--- �������� ���� ---" << endl;
        Computer::ShowInfo(out);
        out << "�����: " << *capacity << " ��" << endl;
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
        cout << "\n===== ���� =====\n";
        cout << "1. ������ ��������\n";
        cout << "2. ������ �������� ����\n";
        cout << "3. �������� ��� ����������\n";
        cout << "4. �������� � ����\n";
        cout << "0. �����\n";
        cout << "��� ����: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "? �������: ������ ����� �� 0 �� 4!\n";
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
            cout << "\n===== �����Ͳ ������ί =====\n";
            if (computers.empty()) {
                cout << "���� ���������� �����.\n";
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
                cerr << "������� �������� �����!\n";
                break;
            }
            for (auto comp : computers)
                comp->ShowInfo(fout);
            fout.close();
            cout << "���������� �������� � ���� computers.txt\n";
            break;
        }
        case 0:
            cout << "����� � ��������...\n";
            break;

        default:
            cout << " ������� ����!\n";
        }

    } while (choice != 0);

    for (auto comp : computers)
        delete comp;

    return 0;
}




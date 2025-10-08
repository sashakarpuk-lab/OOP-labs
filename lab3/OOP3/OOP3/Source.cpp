#include <iostream>
#include <string>
#include <stdexcept>
#include <windows.h>
using namespace std;

class Medicine {
private:
    string name;
    int quantity;
    double price;

public:
    Medicine(string n = "Unknown", int q = 0, double p = 0.0) {
        setQuantity(q);
        setPrice(p);
        name = n;
    }

    void setQuantity(int q) {
        if (q < 0) throw invalid_argument("ʳ������ �� ���� ���� �䒺����!");
        quantity = q;
    }

    void setPrice(double p) {
        if (p < 0) throw invalid_argument("ֳ�� �� ���� ���� �䒺����!");
        price = p;
    }

    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    string getName() const { return name; }

    double getCostByPrescription(int needed) const {
        if (needed <= 0) throw invalid_argument("����������� �������!");
        if (needed > quantity) throw out_of_range("����������� ������!");
        return needed * price;
    }

    Medicine& operator+=(int q) {
        if (quantity + q < 0) throw invalid_argument("����������� ������� �䒺���!");
        quantity += q;
        return *this;
    }

    Medicine& operator-=(int q) {
        if (quantity - q < 0) throw invalid_argument("����������� ������� �䒺���!");
        quantity -= q;
        return *this;
    }

    Medicine operator+(double delta) const {
        if (price + delta < 0) throw invalid_argument("ֳ�� �� ���� ���� �䒺����!");
        return Medicine(name, quantity, price + delta);
    }

    Medicine operator-(double delta) const {
        if (price - delta < 0) throw invalid_argument("ֳ�� �� ���� ���� �䒺����!");
        return Medicine(name, quantity, price - delta);
    }

    void print() const {
        cout << "�����: " << name
            << " | ʳ������: " << quantity
            << " | ֳ��: " << price << " ���" << endl;
    }
};

// ����� � �����
Medicine* findByName(Medicine meds[], int size, const string& searchName) {
    for (int i = 0; i < size; i++) {
        if (meds[i].getName() == searchName) return &meds[i];
    }
    return nullptr;
}

int main() {
    setlocale(LC_ALL, "Ukr");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    const int SIZE = 3;
    Medicine meds[SIZE] = {
        Medicine("Paracetamol", 100, 15.5),
        Medicine("Ibuprofen", 50, 22.0),
        Medicine("Analgin", 70, 12.0)
    };

    int choice;
    do {
        cout << "\n=== ���� ===\n";
        cout << "1. �������� �� ���\n";
        cout << "2. ������ �������\n";
        cout << "3. ������ ����\n";
        cout << "4. ������� �� ��������\n";
        cout << "5. ����� �� ������\n";
        cout << "6. ������ ��� � ��������� �������\n";
        cout << "7. ������ ���������� ���\n";
        cout << "0. �����\n";
        cout << "��� ����: ";
        cin >> choice;

        try {
            if (choice == 1) {
                for (int i = 0; i < SIZE; i++) meds[i].print();
            }
            else if (choice == 2) {
                string name;
                cout << "������ ����� ���: ";
                cin >> name;
                Medicine* m = findByName(meds, SIZE, name);
                if (m) {
                    int delta;
                    cout << "�� ������ ������ �������: ";
                    cin >> delta;
                    *m += delta;
                }
                else cout << "˳�� �� �������!\n";
            }
            else if (choice == 3) {
                string name;
                cout << "������ ����� ���: ";
                cin >> name;
                Medicine* m = findByName(meds, SIZE, name);
                if (m) {
                    double delta;
                    cout << "�� ������ ������ ����: ";
                    cin >> delta;
                    *m = *m + delta;
                }
                else cout << "˳�� �� �������!\n";
            }
            else if (choice == 4) {
                string name;
                cout << "������ ����� ���: ";
                cin >> name;
                Medicine* m = findByName(meds, SIZE, name);
                if (m) {
                    int need;
                    cout << "������ ���� ������� �� ��������: ";
                    cin >> need;
                    cout << "�������: " << m->getCostByPrescription(need) << " ���\n";
                }
                else cout << "˳�� �� �������!\n";
            }
            else if (choice == 5) {
                string name;
                cout << "������ ����� ��� ������: ";
                cin >> name;
                Medicine* m = findByName(meds, SIZE, name);
                if (m) m->print();
                else cout << "˳�� �� �������!\n";
            }
            else if (choice == 6) {
                Medicine* maxMed = &meds[0];
                for (auto& m : meds) {
                    if (m.getQuantity() > maxMed->getQuantity()) {
                        maxMed = &m;
                    }
                }
                cout << "�������� ������� � ���������: ";
                maxMed->print();
            }
            else if (choice == 7) {
                Medicine* maxPriceMed = &meds[0];
                for (auto& m : meds) {
                    if (m.getPrice() > maxPriceMed->getPrice()) {
                        maxPriceMed = &m;
                    }
                }
                cout << "����������� ��������: ";
                maxPriceMed->print();
            }
        }
        catch (exception& e) {
            cerr << "�������: " << e.what() << endl;
        }


    } while (choice != 0);

    cout << "�������� ���������.\n";
    return 0;
}
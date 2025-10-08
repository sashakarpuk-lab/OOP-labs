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
        if (q < 0) throw invalid_argument("Кількість не може бути від’ємною!");
        quantity = q;
    }

    void setPrice(double p) {
        if (p < 0) throw invalid_argument("Ціна не може бути від’ємною!");
        price = p;
    }

    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    string getName() const { return name; }

    double getCostByPrescription(int needed) const {
        if (needed <= 0) throw invalid_argument("Неправильна кількість!");
        if (needed > quantity) throw out_of_range("Недостатньо товару!");
        return needed * price;
    }

    Medicine& operator+=(int q) {
        if (quantity + q < 0) throw invalid_argument("Результуюча кількість від’ємна!");
        quantity += q;
        return *this;
    }

    Medicine& operator-=(int q) {
        if (quantity - q < 0) throw invalid_argument("Результуюча кількість від’ємна!");
        quantity -= q;
        return *this;
    }

    Medicine operator+(double delta) const {
        if (price + delta < 0) throw invalid_argument("Ціна не може бути від’ємною!");
        return Medicine(name, quantity, price + delta);
    }

    Medicine operator-(double delta) const {
        if (price - delta < 0) throw invalid_argument("Ціна не може бути від’ємною!");
        return Medicine(name, quantity, price - delta);
    }

    void print() const {
        cout << "Назва: " << name
            << " | Кількість: " << quantity
            << " | Ціна: " << price << " грн" << endl;
    }
};

// Пошук у масиві
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
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Показати всі ліки\n";
        cout << "2. Змінити кількість\n";
        cout << "3. Змінити ціну\n";
        cout << "4. Вартість за рецептом\n";
        cout << "5. Пошук за назвою\n";
        cout << "6. Знайти ліки з найбільшою кількістю\n";
        cout << "7. Знайти найдорожчі ліки\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        try {
            if (choice == 1) {
                for (int i = 0; i < SIZE; i++) meds[i].print();
            }
            else if (choice == 2) {
                string name;
                cout << "Введіть назву ліків: ";
                cin >> name;
                Medicine* m = findByName(meds, SIZE, name);
                if (m) {
                    int delta;
                    cout << "На скільки змінити кількість: ";
                    cin >> delta;
                    *m += delta;
                }
                else cout << "Ліки не знайдені!\n";
            }
            else if (choice == 3) {
                string name;
                cout << "Введіть назву ліків: ";
                cin >> name;
                Medicine* m = findByName(meds, SIZE, name);
                if (m) {
                    double delta;
                    cout << "На скільки змінити ціну: ";
                    cin >> delta;
                    *m = *m + delta;
                }
                else cout << "Ліки не знайдені!\n";
            }
            else if (choice == 4) {
                string name;
                cout << "Введіть назву ліків: ";
                cin >> name;
                Medicine* m = findByName(meds, SIZE, name);
                if (m) {
                    int need;
                    cout << "Скільки штук потрібно за рецептом: ";
                    cin >> need;
                    cout << "Вартість: " << m->getCostByPrescription(need) << " грн\n";
                }
                else cout << "Ліки не знайдені!\n";
            }
            else if (choice == 5) {
                string name;
                cout << "Введіть назву для пошуку: ";
                cin >> name;
                Medicine* m = findByName(meds, SIZE, name);
                if (m) m->print();
                else cout << "Ліки не знайдені!\n";
            }
            else if (choice == 6) {
                Medicine* maxMed = &meds[0];
                for (auto& m : meds) {
                    if (m.getQuantity() > maxMed->getQuantity()) {
                        maxMed = &m;
                    }
                }
                cout << "Найбільша кількість у препарату: ";
                maxMed->print();
            }
            else if (choice == 7) {
                Medicine* maxPriceMed = &meds[0];
                for (auto& m : meds) {
                    if (m.getPrice() > maxPriceMed->getPrice()) {
                        maxPriceMed = &m;
                    }
                }
                cout << "Найдорожчий препарат: ";
                maxPriceMed->print();
            }
        }
        catch (exception& e) {
            cerr << "Помилка: " << e.what() << endl;
        }


    } while (choice != 0);

    cout << "Програму завершено.\n";
    return 0;
}
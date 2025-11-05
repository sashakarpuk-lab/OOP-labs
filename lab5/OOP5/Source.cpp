#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

const double PI = 3.141592653589793;
const double EPS = 1e-6;

class Shape {
public:
    virtual double area() = 0;
    virtual void show() = 0;
};

class Rectangle : public Shape {
    double a, b;
public:
    Rectangle(double a, double b) : a(a), b(b) {}
    double area() override { return a * b; }
    void show() override {
        cout << "Прямокутник: a=" << a << ", b=" << b
            << "  площа = " << area() << endl;
    }
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double area() override { return PI * r * r; }
    void show() override {
        cout << "Коло: r=" << r
            << "  площа = " << area() << endl;
    }
};

class RightTriangle : public Shape {
    double a, b, c;
public:
    RightTriangle(double a, double b, double c) : a(a), b(b), c(c) {}
    bool isRightTriangle() {
        double sides[3] = { a, b, c };
        sort(sides, sides + 3);
        return fabs(sides[0] * sides[0] + sides[1] * sides[1] - sides[2] * sides[2]) < EPS;
    }
    double area() override {
        if (!isRightTriangle()) {
            cout << " Це НЕ прямокутний трикутник!\n";
            return 0;
        }
        double sides[3] = { a, b, c };
        sort(sides, sides + 3);
        return (sides[0] * sides[1]) / 2;
    }
    void show() override {
        cout << "Трикутник: a=" << a << ", b=" << b << ", c=" << c;
        if (isRightTriangle()) cout << " —  прямокутний";
        else cout << " —  не прямокутний";
        cout << "  площа = " << area() << endl;
    }
};

class Trapezoid : public Shape {
    double a, b, c, d, h;
public:
    Trapezoid(double a, double b, double c, double d, double h)
        : a(a), b(b), c(c), d(d), h(h) {
    }
    bool isTrapezoid() {
        return a != b && h > 0; 
    }
    double area() override {
        if (!isTrapezoid()) {
            cout << " Це НЕ трапецiя!\n";
            return 0;
        }
        return ((a + b) * h) / 2;
    }
    void show() override {
        cout << "Трапецiя: a=" << a << ", b=" << b << ", c=" << c
            << ", d=" << d << ", h=" << h;
        if (isTrapezoid()) cout << " —  правильна трапецiя";
        else cout << " —  не є трапецiєю";
        cout << "  площа = " << area() << endl;
    }
};

double getPositiveNumber(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " Помилка! Введiть додатнє число.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ukr");
    bool keepRunning = true;

    while (keepRunning) {
        cout << "\n=== Обчислення площi фiгур ===\n";
        cout << "1 - Прямокутник\n";
        cout << "2 - Коло\n";
        cout << "3 - Прямокутний трикутник\n";
        cout << "4 - Трапецiя\n";
        cout << "0 - Вийти\n";
        cout << "Ваш вибiр: ";

        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " Невiрний вибiр! Спробуйте ще раз.\n";
            continue;
        }

        if (choice == 0) {
            cout << "Вихiд iз програми. До побачення!\n";
            break;
        }

        Shape* shape = nullptr;

        switch (choice) {
        case 1: {
            double a = getPositiveNumber("Введiть сторону a: ");
            double b = getPositiveNumber("Введiть сторону b: ");
            shape = new Rectangle(a, b);
            break;
        }
        case 2: {
            double r = getPositiveNumber("Введiть радiус r: ");
            shape = new Circle(r);
            break;
        }
        case 3: {
            double a = getPositiveNumber("Введiть сторону a: ");
            double b = getPositiveNumber("Введiть сторону b: ");
            double c = getPositiveNumber("Введiть сторону c: ");
            shape = new RightTriangle(a, b, c);
            break;
        }
        case 4: {
            double a = getPositiveNumber("Введiть основу a: ");
            double b = getPositiveNumber("Введiть основу b: ");
            double c = getPositiveNumber("Введiть бiчну сторону c: ");
            double d = getPositiveNumber("Введiть бiчну сторону d: ");
            double h = getPositiveNumber("Введiть висоту h: ");
            shape = new Trapezoid(a, b, c, d, h);
            break;
        }
        default:
            cout << " Невiрний вибiр! Спробуйте ще раз.\n";
            continue;
        }

        cout << "\n--- Результат ---\n";
        shape->show();
        delete shape;
    }

    return 0;
}

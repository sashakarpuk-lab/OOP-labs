#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Functions {
private:
    double y, z, b,x;

public:
    Functions(int) {
        y = 0.47 * 5;
        z = -1.32 * 5;
        b = 0;
        x = 0.48 * 5;
    }

    double calc_b(double x) {
        double numerator = pow(x, 2) + pow(z, 2) / pow(tan(fabs(pow(x, 0.3))), 2);
        double denominator = 3 + x + (pow(y, 2) / tgamma(2)) + (pow(z, 3) / tgamma(3));
        double term1 = numerator / denominator;
        double term2 = pow(log(fabs(y / z)), 0.3 * (1 / 3));
        b = term1 + term2;
        return b;
    }

    double calc_a(double x) {
        double numerator = 2 * cos(pow(fabs(x), 1 / 3) - pow(x, 2) / 6);
        double denominator = z / b + pow(sin(pow(y + z, 3)), 2);
        double term1 = numerator / denominator;
        double term2 = pow(pow(log(fabs(z)), 2), 0.6);

        return term1 + term2;
    }
    void printResults() {
        cout << "b(x,y,z) = " << calc_b(x) << endl;
        cout << "a(x,y,z,b) = " << calc_a(x) << endl;
    }
};
int main() {
    setlocale(LC_ALL, "Ukr");
    Functions f(5);
    f.printResults();

    double xn = -1, xk = 1, dx = 0.2;

    cout << "==========================================================\n";
    cout << "          Табуляцiя функцiй a(x,y,z,b) та b(x,y,z)        \n";
    cout << "==========================================================\n";
    cout << setw(10) << "x"
        << setw(20) << "b(x,y,z)"
        << setw(20) << "a(x,y,z,b)" << "\n";
    cout << "----------------------------------------------------------\n";

    for (double x = xn; x <= xk; x += dx) {
        double b = f.calc_b(x);
        double a = f.calc_a(x);

        cout << setw(10) << fixed << setprecision(2) << x
            << setw(20) << setprecision(6) << b
            << setw(20) << setprecision(6) << a << "\n";
    }

    cout << "==========================================================\n";

    return 0;
}






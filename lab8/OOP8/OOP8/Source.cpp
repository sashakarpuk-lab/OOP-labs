#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <functional>
#include <cstdlib>
using namespace std;

void main() {
    setlocale(LC_ALL, "Ukr");
    vector<int> v, t(9);
    vector<int> ::iterator pos, imin, imax;
    int n;
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
        v.push_back(-50 + rand() % (50+51));
    cout<<" Створений вектор" <<endl;
    for (pos = v.begin(); pos != v.end(); ++pos)
        cout << *pos << " ";
    cout<<"\n";
    imax = max_element(v.begin(), v.end());
    cout << " Max element ="<< *imax <<endl;

    imax = find(v.begin(), v.end(), *imax);
    cout << "Позицiя max елемента=" << imax - v.begin() <<endl;


    auto lastPositive = find_if(v.rbegin(), v.rend(), [](double x) { return x > 0; });

    double sum = 0;

    if (lastPositive != v.rend()) {
        int lastPosIndex = (v.rend() - lastPositive - 1);

        sum = accumulate(v.begin(), v.begin() + lastPosIndex, 0.0);
        cout << "Сума елементів до останнього додатного: " << sum << endl;
    }
    else {
        cout << "Додатних елементів немає. Сума = 0\n";
    }

    double a, b;
    cout << "Введіть інтервал [a, b]: ";
    cin >> a >> b;
    auto newEnd = remove_if(v.begin(), v.end(),
        [a, b](double x) {
            return abs(x) >= a && abs(x) <= b;
        });

    fill(newEnd, v.end(), 0);

    cout << "Після стиснення масиву:\n";
    for (double x : v) cout << x << " ";
    cout << endl;


}


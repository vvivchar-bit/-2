#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

double compute(double x, double a) {
    if (x < 0) {
        return x + a * exp(x);
    } else if (x >= 0 && a <= 0) {
        return fabs(x) - log(pow(x, 2));
    } else if (x > 0 && x <= 2 && a > 0) {
        return log(x) / log(a);
    } else {
        cout << "Function not defined for these values\n";
        return NAN;
    }
}

int main() {
    cout << fixed << setprecision(6);
    while (true) {
        cout << "Enter x: ";
        double x;
        if (!(cin >> x)) {
            cout << "Invalid input\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cout << "Enter a: ";
        double a;
        if (!(cin >> a)) {
            cout << "Invalid input\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        double y = compute(x, a);
        if (!isnan(y)) {
            cout << "y = " << y << "\n";
        }
        cout << "Again? (y/n): ";
        char c;
        cin >> c;
        if (c != 'y' && c != 'Y') break;
    }
    return 0;
}


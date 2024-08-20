// Baekjoon02936.cpp
#include <iostream>

using namespace std;

int main(void) {
    const double area = 15625 * 2;

    double a, b;
    cin >> a >> b;

    double x, y;
    if (a == 0 && b == 0)
        x = 125.0, y = 125.0;
    else if (a == 0) {
        if (b <= 125.0) {
            x = area / (250 - b);
            y = 250 - x;
        } else {
            x = area / b;
            y = 0.0;
        }
    } else if (b == 0) {
        if (a <= 125.0) {
            y = area / (250 - a);
            x = 250 - y;
        } else {
            y = area / a;
            x = 0.0;
        }
    } else {
        if (a > b) {
            x = 0.0;
            y = 250 - (area / a);
        } else {
            y = 0.0;
            x = 250 - (area / b);
        }
    }

    cout << fixed;
    cout.precision(2);

    cout << x << ' ' << y << '\n';

    return 0;
}
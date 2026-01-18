// Baekjoon16486.cpp
#include <iostream>

using namespace std;

int main(void) {
    const double PI = 3.141592;

    double d1, d2;
    cin >> d1 >> d2;

    double ans = 2.0 * (d2 * PI + d1);

    cout << fixed;
    cout.precision(6);

    cout << ans << '\n';

    return 0;
}

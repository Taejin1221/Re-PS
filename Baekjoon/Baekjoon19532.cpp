// Baekjoon19532.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int x, y;
    bool isFind = false;
    for (x = -999; x <= 999; x++) {
        for (y = -999; y <= 999; y++) {
            if (a * x + b * y == c && d * x + e * y == f) {
                isFind = true;
                break;
            }
        }

        if (isFind)
            break;
    }

    cout << x << ' ' << y << '\n';

    return 0;
}
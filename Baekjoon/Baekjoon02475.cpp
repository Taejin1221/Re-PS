// Baekjoon02475.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    cout << (a * a + b * b + c * c + d * d + e * e) % 10 << '\n';

    return 0;
}
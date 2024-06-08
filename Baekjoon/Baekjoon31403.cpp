// Baekjoon31403.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;

    cout << a + b - c << '\n';

    int bDigit = 1000;
    while (b / bDigit == 0)
        bDigit /= 10;

    a = a * bDigit * 10 + b;
    cout << a - c << '\n';

    return 0;
}
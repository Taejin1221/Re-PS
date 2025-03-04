// Baekjoon21612.cpp
#include <iostream>

using namespace std;

int main(void) {
    int b;
    cin >> b;

    cout << (5 * b - 400) << '\n';
    if (b < 100)
        cout << 1;
    else if (b > 100)
        cout << -1;
    else
        cout << 0;
    cout << '\n';

    return 0;
}

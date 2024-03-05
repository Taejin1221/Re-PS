// Baekjoon14215.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;

    int maxSide = max(a, max(b, c));
    if (maxSide < a + b + c - maxSide)
        cout << a + b + c;
    else
        cout << (a + b + c - maxSide) * 2 - 1;
    cout << '\n';

    return 0;
}
// Baekjoon01193.cpp
#include <iostream>

using namespace std;

int main(void) {
    int x;
    cin >> x;

    int i;
    for (i = 1; i * (i + 1) / 2 < x; i++) { }

    int j = x - i * (i - 1) / 2 - 1;
    if (i % 2)
        cout << i - j << '/' << 1 + j << '\n';
    else
        cout << 1 + j << '/' << i - j << '\n';

    return 0;
}
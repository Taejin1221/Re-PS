// Baekjoon04153.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    while (a != 0 && b != 0 && c != 0) {
        if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
            cout << "right";
        else
            cout << "wrong";
        cout << '\n';

        cin >> a >> b >> c;
    }

    return 0;
}
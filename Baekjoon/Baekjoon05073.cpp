// Baekjoon05073.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;

    while (a != 0 && b != 0 && c != 0) {
        int maxSide = max(a, max(b, c));

        if (maxSide >= a + b + c - maxSide)
            cout << "Invalid";
        else {
            if (a == b && b == c)
                cout << "Equilateral";
            else if (a == b || b == c || c == a)
                cout << "Isosceles";
            else
                cout << "Scalene";
        }
        cout << '\n';

        cin >> a >> b >> c;
    }

    return 0;
}
// Baekjoon10101.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c != 180)
        cout << "Error";
    else {
        if (a == b && b == c)
            cout << "Equilateral";
        else if (a == b || b == c || c == a)
            cout << "Isosceles";
        else
            cout << "Scalene";
    }
    cout << '\n';

    return 0;
}
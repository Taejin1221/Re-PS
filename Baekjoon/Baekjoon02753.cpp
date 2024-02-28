// Baekjoon02753.cpp
#include <iostream>

using namespace std;

int main(void) {
    int year;
    cin >> year;

    if (year % 400 == 0)
        cout << 1;
    else if (year % 100 == 0)
        cout << 0;
    else if (year % 4 == 0)
        cout << 1;
    else
        cout << 0;
    cout << '\n';

    return 0;
}
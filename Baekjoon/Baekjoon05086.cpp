// Baekjoon05086.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    while (a != 0 && b != 0) {
        if (a % b == 0)
            cout << "multiple";
        else if (b % a == 0)
            cout << "factor";
        else
            cout << "neither";
        cout << '\n';

        cin >> a >> b;
    }

    return 0;
}
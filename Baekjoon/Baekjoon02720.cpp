// Baekjoon02720.cpp
#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int change;
        cin >> change;

        cout << change / 25 << ' ';
        change %= 25;

        cout << change / 10 << ' ';
        change %= 10;

        cout << change / 5 << ' ';
        change %= 5;

        cout << change / 1 << '\n';
    }

    return 0;
}
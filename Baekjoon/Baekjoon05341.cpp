// Baekjoon05341.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    while (n != 0) {
        cout << (n * (n + 1) / 2) << '\n';

        cin >> n;
    }

    return 0;
}
// Baekjoon02444.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++)
            cout << ' ';
        for (int j = 0; j < (i - 1) * 2 + 1; j++)
            cout << '*';
        cout << '\n';
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n - i; j++)
            cout << ' ';
        for (int j = 0; j < (i - 1) * 2 + 1; j++)
            cout << '*';
        cout << '\n';
    }

    return 0;
}
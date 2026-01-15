// Baekjoon10992.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
        cout << ' ';
    cout << '*' << '\n';

    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < (n - i - 1); j++)
            cout << ' ';
        cout << '*';

        for (int j = 0; j < (2 * i - 1); j++)
            cout << ' ';
        cout << '*' << '\n';
    }

    if (n > 1) {
        for (int i = 0; i < (2 * n - 1); i++)
            cout << '*';
        cout << '\n';
    }

    return 0;
}

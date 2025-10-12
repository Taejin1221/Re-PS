// Baekjoon07595.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    while (n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++)
                cout << '*';
            cout << '\n';
        }

        cin >> n;
    }

    return 0;
}

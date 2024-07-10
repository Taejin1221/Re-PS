// Baekjoon10990.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++)
            cout << ' ';
        cout << '*';
        for (int j = 0; j < (n - i - 1) * 2 - 1; j++)
            cout << ' ';
        if (i != n - 1)
            cout << '*';

        cout <<'\n';
    }

    return 0;
}
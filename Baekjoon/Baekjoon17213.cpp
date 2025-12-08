// Baekjoon17213.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, r;
    cin >> n >> r;

    int c[31][31];
    for (int i = 0; i <= r; i++)
        c[i][0] = c[i][i] = 1;

    for (int i = 2; i <= r; i++) {
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    cout << c[r - 1][r - n] << '\n';

    return 0;
}

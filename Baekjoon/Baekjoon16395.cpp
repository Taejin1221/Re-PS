// Baekjoon16395.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    int combination[30][30];
    combination[0][0] = 1;
    combination[1][0] = 1;
    combination[1][1] = 1;

    for (int i = 2; i < n; i++) {
        combination[i][0] = 1;
        for (int j = 1; j < i; j++)
            combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
        combination[i][i] = 1;
    }

    cout << combination[n - 1][k - 1] << '\n';

    return 0;
}
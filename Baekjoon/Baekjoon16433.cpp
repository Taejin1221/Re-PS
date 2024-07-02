// Baekjoon16433.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, r, c;
    cin >> n >> r >> c;

    char farm[2][100][100] = { { { '\0', }, }, };
    farm[0][0][0] = 'v';
    farm[1][0][0] = '.';
    for (int k = 0; k < 2; k++) {
        for (int i = 1; i < n; i++)
            farm[k][0][i] = (farm[k][0][i - 1] == 'v' ? '.' : 'v');

        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                farm[k][i][j] = (farm[k][i - 1][j] == 'v' ? '.' : 'v');
    }

    int ansIdx = farm[0][r - 1][c - 1] == 'v' ? 0 : 1;
    for (int i = 0; i < n; i++)
        cout << farm[ansIdx][i] << '\n';

    return 0;
}
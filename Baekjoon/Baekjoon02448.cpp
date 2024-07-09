// Baekjoon02448.cpp
#include <iostream>

using namespace std;

char ans[3'072][6'144] = { { 0, }, };

void solve(int row, int col, int rowSize, int colSize) {
    if (rowSize == 3) {
        ans[row][col + 2] = '*';
        ans[row + 1][col + 1] = ans[row + 1][col + 3] = '*';
        ans[row + 2][col] = ans[row + 2][col + 1] = ans[row + 2][col + 2] = ans[row + 2][col + 3] = ans[row + 2][col + 4] = '*';
    } else {
        int rowHalf = rowSize / 2, colHalf = colSize / 2;
        solve(row, col + colSize / 4 + 1, rowHalf, colHalf);
        solve(row + rowHalf, col, rowHalf, colHalf);
        solve(row + rowHalf, col + colHalf + 1, rowHalf, colHalf);
    }
}

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n * 2 - 1; j++)
            ans[i][j] = ' ';

    solve(0, 0, n, n * 2 - 1);

    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';

    return 0;
}
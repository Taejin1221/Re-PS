// Baekjoon01799.cpp
#include <iostream>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

int n, result;
bool d2[20];
int board[10][10];

int getD2Idx(int row, int col) {
    return row + col;
}

void solve(int row, int col, int bishop) {
    result = max(result, bishop);
    if (col >= n)
        return;

    int nextRow, nextCol;
    if (row == 0) {
        nextRow = row;
        nextCol = col + 2;
    } else if (row == 1) {
        nextRow = 0;
        nextCol = 1;
    } else {
        nextRow = row - 2;
        nextCol = col;
    }

    for (int currRow = row, currCol = col; currRow < n && currCol < n; currRow++, currCol++) {
        if (board[currRow][currCol] == 1) {
            int d2Idx = getD2Idx(currRow, currCol);
            if (!d2[d2Idx]) {
                d2[d2Idx] = true;
                solve(nextRow, nextCol, bishop + 1);
                d2[d2Idx] = false;
            }
        }
    }
    solve(nextRow, nextCol, bishop);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int ans = 0;
    solve(n - 1, 0, 0);
    ans += result;

    result = 0;
    solve(n - 2, 0, 0);
    ans += result;

    cout << ans << '\n';

    return 0;
}

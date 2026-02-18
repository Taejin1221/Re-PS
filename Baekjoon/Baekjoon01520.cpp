// Baekjoon01520.cpp
#include <iostream>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m, height[500][500];
int dp[500][500];

int solve(int row, int col) {
    if (dp[row][col] == -1) {
        dp[row][col] = 0;
        for (int i = 0; i < 4; i++) {
            int newRow = row + moves[i][0], newCol = col + moves[i][1];
            if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
                if (height[newRow][newCol] > height[row][col])
                    dp[row][col] += solve(newRow, newCol);
            }
        }
    }

    return dp[row][col];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> height[i][j];
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 1;

    cout << solve(n - 1, m - 1) << '\n';

    return 0;
}

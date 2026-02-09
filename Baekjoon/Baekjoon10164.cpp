// Baekjoon10164.cpp
#include <iostream>

using namespace std;

int getPathNum(int row, int col) {
    int dp[15][15] = { { 1, }, };
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i != 0)
                dp[i][j] += dp[i - 1][j];

            if (j != 0)
                dp[i][j] += dp[i][j - 1];
        }
    }

    return dp[row - 1][col - 1];
}

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;

    int tempK = 1;
    int rowK = 0, colK = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++, tempK++)
            if (tempK == k)
                rowK = i, colK = j;

    int ans = getPathNum(rowK + 1, colK + 1) * getPathNum(n - rowK, m - colK);
    cout << ans << '\n';

    return 0;
}

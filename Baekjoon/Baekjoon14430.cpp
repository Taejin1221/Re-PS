// Baekjoon14430.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int area[300][300];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> area[i][j];

    int dp[300][300];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = area[i][j];

            if (i > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + area[i][j]);

            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + area[i][j]);
        }
    }

    cout << dp[n - 1][m - 1] << '\n';

    return 0;
}
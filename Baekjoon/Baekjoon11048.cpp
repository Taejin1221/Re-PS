#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int maze[1'000][1'000];
    int dp[1'000][1'000] = { { 0, }, };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];

            if (i == 0 && j == 0)
                dp[i][j] = maze[i][j];
            
            if (i != 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + maze[i][j]);
            
            if (j != 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + maze[i][j]);

            if (i != 0 && j != 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + maze[i][j]);
        }
    }

    cout << dp[n - 1][m - 1] << '\n';

    return 0;
}

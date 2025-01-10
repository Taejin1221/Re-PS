// Baekjoon17069.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int home[32][32];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> home[i][j];

    ll dp[3][32][32] = { { 0, }, };
    dp[0][0][1] = 1;
    for (int i = 2; i < n; i++)
        if (home[0][i] != 1)
            dp[0][0][i] = dp[0][0][i - 1];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (home[i][j] == 1)
                continue;

            if (j != 0) {
                dp[0][i][j] = dp[0][i][j - 1] + dp[2][i][j - 1];
                if (home[i - 1][j] != 1 && home[i][j - 1] != 1)
                    dp[2][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
            }
            dp[1][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];
        }
    }

    cout << dp[0][n - 1][n - 1] + dp[1][n - 1][n - 1] + dp[2][n - 1][n - 1] << '\n';

    return 0;
}

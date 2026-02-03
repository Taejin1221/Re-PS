// Baekjoon24392.cpp
#include <iostream>

#define MAX 10

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    const ll MOD = 1'000'000'007LL;

    int n, m;
    cin >> n >> m;

    bool glass[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> glass[i][j];

    ll dp[MAX][MAX] = { { 0LL, }, };
    for (int i = 0; i < m; i++)
        dp[n - 1][i] = (glass[n - 1][i] ? 1LL : 0LL);

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (glass[i][j]) {
                if (j > 0)
                    dp[i][j] += dp[i + 1][j - 1];

                if (j < m - 1)
                    dp[i][j] += dp[i + 1][j + 1];

                dp[i][j] += dp[i + 1][j];

                dp[i][j] %= MOD;
            }
        }
    }

    ll ans = 0LL;
    for (int i = 0; i < m; i++)
        ans = (ans + dp[0][i]) % MOD;

    cout << ans << '\n';

    return 0;
}

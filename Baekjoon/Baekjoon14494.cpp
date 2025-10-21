// Baekjoon14494.cpp
#include <iostream>

#define MOD 1'000'000'007

using namespace std;

using ll = long long;

int main(void) {
    int n, m;
    cin >> n >> m;

    ll dp[1'000][1'000];
    for (int i = 0; i < n; i++)
        dp[i][0] = 1LL;
    for (int j = 0; j < m; j++)
        dp[0][j] = 1LL;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
        }
    }

    cout << dp[n - 1][m - 1] << '\n';

    return 0;
}

#include <iostream>

#define MOD 1'000'000'007

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    ll dp[5][200'000] = { { 0, }, };
    dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = dp[4][0] = 1;
    for (int i = 1; i < n; i++) {
        dp[0][i] = (dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1] + dp[4][i - 1]) % MOD;
        dp[1][i] = (dp[0][i - 1] + dp[3][i - 1] + dp[4][i - 1]) % MOD;
        dp[2][i] = (dp[0][i - 1] + dp[4][i - 1]) % MOD;
        dp[3][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
        dp[4][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % MOD;
    }

    ll sum = 0LL;
    for (int i = 0; i < 5; i++)
        sum += dp[i][n - 1];
    cout << (sum % MOD) << '\n';

    return 0;
}

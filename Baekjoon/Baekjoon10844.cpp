// Baekjoon10844.cpp
#include <iostream>

#define MOD 1'000'000'000

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int dp[10][101] = { { 0, }, };
    for (int i = 0; i <= 9; i++)
        dp[i][1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[0][i] = dp[1][i - 1];
        for (int j = 1; j <= 8; j++)
            dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % MOD;
        dp[9][i] = dp[8][i - 1];
    }

    int ans = 0;
    for (int i = 1; i <= 9; i++)
        ans = (ans + dp[i][n]) % MOD;

    cout << ans << '\n';

    return 0;
}
// Baekjoon01562.cpp
#include <iostream>

#include <string>

#define MOD 1'000'000'000

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int dp[101][10][1024] = { 0, }; // { length, digit, visited }
    for (int i = 0; i <= 9; i++)
        dp[1][i][1 << i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int k = 0; k <= 1023; k++) {
            if (dp[i - 1][1][k] != 0) {
                dp[i][0][k | (1 << 0)] += dp[i - 1][1][k];
                dp[i][0][k | (1 << 0)] %= MOD;
            }
        }

        for (int k = 0; k <= 1023; k++) {
            if (dp[i - 1][8][k] != 0) {
                dp[i][9][k | (1 << 9)] += dp[i - 1][8][k];
                dp[i][9][k | (1 << 9)] %= MOD;
            }
        }

        for (int j = 1; j < 9; j++) {
            for (int k = 0; k <= 1023; k++) {
                if (dp[i - 1][j - 1][k] != 0) {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
                    dp[i][j][k | (1 << j)] %= MOD;
                }

                if (dp[i - 1][j + 1][k] != 0) {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
                    dp[i][j][k | (1 << j)] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 9; i++)
        ans = (ans + dp[n][i][1023]) % MOD;
    cout << ans << '\n';

    return 0;
}
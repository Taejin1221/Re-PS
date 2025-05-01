// Baekjoon11051.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    int dp[1'001][1'001];
    dp[0][0] = dp[1][0] = dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j < i; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10'007;
        dp[i][i] = 1;
    }

    cout << dp[n][k] << '\n';

    return 0;
}

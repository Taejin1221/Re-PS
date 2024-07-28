// Baekjoon13270.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> fib[2];
    fib[0].push_back(2);
    fib[0].push_back(3);
    fib[1].push_back(1);
    fib[1].push_back(2);

    while (fib[0].back() < n) {
        int size = fib[0].size();

        fib[1].push_back(fib[0].back());
        fib[0].push_back(fib[0][size - 1] + fib[0][size - 2]);
    }

    vector<vector<int>> dp(2, vector<int> (n + 1));
    dp[0][2] = fib[1][0];
    dp[1][2] = fib[1][0];

    dp[0][3] = fib[1][1];
    dp[1][3] = fib[1][1];

    for (int i = 4; i <= n; i++) {
        dp[0][i] = dp[0][i - fib[0][0]] + fib[1][0];
        dp[1][i] = dp[1][i - fib[0][0]] + fib[1][0];
        for (int j = 1; i - fib[0][j] > 1; j++) {
            dp[0][i] = min(dp[0][i], dp[0][i - fib[0][j]] + fib[1][j]);
            dp[1][i] = max(dp[1][i], dp[1][i - fib[0][j]] + fib[1][j]);
        }
    }

    cout << dp[0][n] << ' ' << dp[1][n] << '\n';

    return 0;
}
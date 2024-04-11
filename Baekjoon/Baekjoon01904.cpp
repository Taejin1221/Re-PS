// Baekjoon01904.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 0, dp[1] = 1, dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15'746;

    cout << dp[n] << '\n';

    return 0;
}
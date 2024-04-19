// Baekjoon11726.cpp
#include <iostream>

#include <vector>

#define MOD 10'007

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[1] = 1, dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    cout << dp[n] << '\n';

    return 0;
}
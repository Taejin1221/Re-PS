// Baekjoon01003.cpp
#include <iostream>

using namespace std;

int main(void) {
    int dp[2][41] = { { 1, }, { 0, 1, }, };
    for (int i = 2; i <= 40; i++) {
        dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
        dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout << dp[0][n] << ' ' << dp[1][n] << '\n';
    }

    return 0;
}
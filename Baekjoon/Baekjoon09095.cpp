// Baekjoon09095.cpp
#include <iostream>

using namespace std;

int main(void) {
    int dp[11] = { 0, 1, 2, 4, };
    for (int i = 4; i <= 10; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;
}
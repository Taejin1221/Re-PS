// Baekjoon02579.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int stair[300];
    for (int i = 0; i < n; i++)
        cin >> stair[i];

    int dp[2][301];
    dp[0][0] = dp[1][0] = 0;
    dp[0][1] = stair[0]; dp[1][1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]) + stair[i - 1];
        dp[1][i] = dp[0][i - 1] + stair[i - 1];
    }
    cout << max(dp[0][n], dp[1][n]) << '\n';

    return 0;
}
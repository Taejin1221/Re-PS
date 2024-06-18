// Baekjoon09465.cpp
#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int sticker[2][100'000];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> sticker[i][j];

    if (n == 1)
        cout << max(sticker[0][0], sticker[1][0]);
    else if (n == 2) {
        cout << max(sticker[0][0] + sticker[1][1], sticker[1][0] + sticker[0][1]);
    } else {
        int dp[2][100'000];
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];

        dp[0][1] = sticker[1][0] + sticker[0][1];
        dp[1][1] = sticker[0][0] + sticker[1][1];

        for (int i = 2; i < n; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]);
    }
    cout << '\n';    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
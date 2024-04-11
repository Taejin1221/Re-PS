// Baekjoon02156.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int wine[10'000];
    for (int i = 0; i < n; i++)
        cin >> wine[i];

    int ans = wine[0];
    int dp[3][10'000] = { { 0, }, };
    dp[0][0] = 0, dp[1][0] = wine[0], dp[2][0] = wine[0];
    for (int i = 1; i < n; i++) {
        dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
        dp[1][i] = dp[0][i - 1] + wine[i];
        dp[2][i] = dp[1][i - 1] + wine[i];

        ans = max(max(ans, dp[0][i]), max(dp[1][i], dp[2][i]));
    }

    cout << ans << '\n';

    return 0;
}
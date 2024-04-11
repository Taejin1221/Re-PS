// Baekjoon01932.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int triangle[500][500], dp[500][500];
    cin >> triangle[0][0];
    dp[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
            dp[i][j] = (j ? max(dp[i - 1][j - 1], dp[i - 1][j]) : dp[i - 1][j]) + triangle[i][j];
        }
    }

    int ans = dp[n - 1][0];
    for (int i = 1; i < n; i++)
        ans = max(ans, dp[n - 1][i]);

    cout << ans << '\n';

    return 0;
}
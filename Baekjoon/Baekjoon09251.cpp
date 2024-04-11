// Baekjoon09251.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    int dp[1'000][1'000];
    dp[0][0] = a[0] == b[0];
    for (int i = 1; i < n; i++)
        dp[i][0] = (a[i] == b[0] ? 1 : dp[i - 1][0]);

    for (int i = 1; i < m; i++)
        dp[0][i] = (a[0] == b[i] ? 1 : dp[0][i - 1]);

    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n - 1][m - 1] << '\n';

    return 0;
}
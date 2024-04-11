// Baekjoon12865.cpp
#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    int ans = 0;
    vector<vector<int>> dp(k + 1, vector<int> (n));
    for (int i = 1; i <= k; i++) {
        dp[i][0] = (arr[0].first <= i) ? arr[0].second : 0;
        for (int j = 1; j < n; j++) {
            if (arr[j].first <= i)
                dp[i][j] = max(dp[i][j - 1], dp[i - arr[j].first][j - 1] + arr[j].second);
            else
                dp[i][j] = dp[i][j - 1];
        }

        ans = max(ans, dp[i][n - 1]);
    }

    cout << ans << '\n';

    return 0;
}
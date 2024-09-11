// Baekjoon07579.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pii app[100];
    int dp[10'001] = { 0, };
    for (int i = 0; i < n; i++)
        cin >> app[i].first;
    for (int i = 0; i < n; i++)
        cin >> app[i].second;

    for (int i = 0; i < n; i++) {
        for (int j = 10'000; j >= 0; j--) {
            int cost = j - app[i].second;
            if (cost >= 0 && dp[cost] != 0)
                dp[j] = max(dp[j], dp[cost] + app[i].first);
        }
        dp[app[i].second] = max(dp[app[i].second], app[i].first);
    }

    int ans;
    for (int i = 0; i <= 10'000; i++) {
        if (dp[i] >= m) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
// Baekjoon11060.cpp
#include <iostream>

#include <queue>

using namespace std;

using pii = pair<int, int>;

// 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[1'000];

    /** Solution 1: BFS */
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    queue<pii> q;
    bool visited[1'001] = { false, };

    q.push({ 0, 0 });
    visited[0] = true;

    int ans = -1;
    while (!q.empty()) {
        pii curr = q.front(); q.pop();

        if (curr.first == n - 1) {
            ans = curr.second;
            break;
        }

        for (int i = 1; i <= arr[curr.first]; i++) {
            int next = curr.first + i;
            if (next < n && !visited[next]) {
                visited[next] = true;
                q.push({ next, curr.second + 1 });
            }
        }
    }

    cout << ans << '\n';

    /** Solution 2: DP */
    int dp[1'000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 0x3f3f3f3f;
    }

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] != 0x3f3f3f3f) {
            for (int j = 1; j <= arr[i] && i + j < n; j++) {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
    }

    if (dp[n - 1] == 0x3f3f3f3f)
        cout << -1;
    else
        cout << dp[n - 1];
    cout << '\n';

    return 0;
}
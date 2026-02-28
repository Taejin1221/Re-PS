// Baekjoon33677.cpp
#include <iostream>

#include <queue>

using namespace std;

using pii = pair<int, int>;
using ll = long long;

int main(void) {
    int n;
    cin >> n;

    queue<ll> q;
    pii dp[1'000'001] = { { 0, 0 }, };
    for (int i = 1; i <= n; i++)
        dp[i] = { 0x3f3f3f3f, 0x3f3f3f3f };

    q.push(0LL);
    while (!q.empty()) {
        ll curr = q.front(); q.pop();
        int currTime = dp[curr].first, currWater = dp[curr].second;

        if (curr == n)
            break;

        ll nextTime = currTime + 1;
        ll nexts[3][2] = { { curr + 1, currWater + 1 }, { curr * 3, currWater + 3 }, { curr * curr, currWater + 5 } };
        for (int i = 0; i < 3; i++) {
            ll nextHeight = nexts[i][0], nextWater = nexts[i][1];
            if (nextHeight <= n) {
                if (dp[nextHeight].first > nextTime) {
                    dp[nextHeight] = { nextTime, nextWater };
                    q.push(nextHeight);
                } else if (dp[nextHeight].first == nextTime)
                    dp[nextHeight].second = min(dp[nextHeight].second, (int)nextWater);
            }
        }
    }

    cout << dp[n].first << ' ' << dp[n].second << '\n';

    return 0;
}

// Baekjoon01374.cpp
#include <iostream>

#include <queue>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> lectures(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        cin >> lectures[i].first >> lectures[i].second;
    }
    sort(lectures.begin(), lectures.end());

    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top() <= lectures[i].first)
            pq.pop();

        pq.push(lectures[i].second);
        ans = max(ans, (int)pq.size());
    }

    cout << ans << '\n';

    return 0;
}

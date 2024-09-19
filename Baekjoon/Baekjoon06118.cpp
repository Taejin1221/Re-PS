// Baekjoon06118.cpp
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adjList[20'001];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjList[v].push_back(u);
        adjList[u].push_back(v);
    }

    queue<pii> q;
    int distance[20'001];
    fill(distance, distance + n + 1, -1);

    q.push({ 1, 0 });
    distance[1] = 0;

    int maxDis = 0;
    while (!q.empty()) {
        pii curr = q.front(); q.pop();

        for (int& adjV : adjList[curr.first]) {
            if (distance[adjV] == -1) {
                int nextDis = curr.second + 1;

                distance[adjV] = nextDis;
                q.push({ adjV, nextDis });

                maxDis = max(maxDis, nextDis);
            }
        }
    }

    pii ans = { 1, 1 };
    for (int i = 1; i <= n; i++) {
        if (distance[i] == maxDis) {
            if (distance[ans.first] < distance[i]) {
                ans = { i, 1 };
            } else
                ans.second++;
        }
    }

    cout << ans.first << ' ' << maxDis << ' ' << ans.second << '\n';

    return 0;
}
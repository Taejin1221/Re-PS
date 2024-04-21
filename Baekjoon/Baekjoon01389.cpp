// Baekjoon01389.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> connect(n + 1);
    int ans = 0;
    connect[0] = 1 << 20;
    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n + 1);
        visited[i] = true;

        queue<pii> q;
        q.push({ i, 0 });
        
        while (!q.empty()) {
            pii curr = q.front(); q.pop();
            connect[i] += curr.second;

            for (int& next : adjList[curr.first]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({ next, curr.second + 1 });
                }
            }
        }
        
        ans = (connect[ans] > connect[i]) ? i : ans;
    }

    cout << ans << '\n';

    return 0;
}
// Baekjoon01260.cpp
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<vector<int>> adjList;

void dfs(int curr) {
    cout << curr << ' ';
    for (int& next : adjList[curr]) {
        if (!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    adjList = vector<vector<int>> (n + 1, vector<int> ());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(adjList[i].begin(), adjList[i].end());

    visited = vector<bool> (n + 1);

    visited[v] = true;
    dfs(v);
    cout << '\n';

    visited = vector<bool> (n + 1);

    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        cout << curr << ' ';

        for (int& next : adjList[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    cout << '\n';

    return 0;
}
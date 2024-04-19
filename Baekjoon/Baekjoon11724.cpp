// Baekjoon11724.cpp
#include <iostream>

#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> adjList;

void dfs(int curr) {
    for (int& next : adjList[curr]) {
        if (!visited[next]) {
            visited[next] = true;

            dfs(next);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    adjList = vector<vector<int>> (n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    visited = vector<bool> (n + 1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;

            dfs(i);

            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
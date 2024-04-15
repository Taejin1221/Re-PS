// Baekjoon02606.cpp
#include <iostream>

#include <vector>

using namespace std;

int n, ans;
vector<bool> visited;
vector<vector<int>> adjList;

void dfs(int curr) {
    for (int& next : adjList[curr]) {
        if (!visited[next]) {
            visited[next] = true, ans++;
            dfs(next);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int m;
    cin >> m;

    adjList = vector<vector<int>> (n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    visited = vector<bool> (n + 1);
    visited[1] = true;
    dfs(1);

    cout << ans << '\n';

    return 0;
}
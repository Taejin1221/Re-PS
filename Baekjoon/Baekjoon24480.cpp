// Baekjoon24480.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int n, t = 1;
int ans[100'001];
vector<int> adjList[100'001];

void dfs(int curr) {
    ans[curr] = t++;

    for (int& adjV : adjList[curr])
        if (ans[adjV] == 0)
            dfs(adjV);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, s;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(adjList[i].begin(), adjList[i].end(), greater<>());
    dfs(s);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';

    return 0;
}

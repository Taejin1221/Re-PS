// Baekjoon01967.cpp
#include <iostream>

#include <vector>

#define V first
#define D second

using namespace std;

using pii = pair<int, int>;

int ans;
vector<bool> isLeaf;
vector<vector<pii>> adjList;

void dfs(int me, int mom, int currDis) {
    if (isLeaf[me])
        ans = max(ans, currDis);

    for (pii& adj : adjList[me])
        if (adj.V != mom)
            dfs(adj.V, me, currDis + adj.D);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    adjList = vector<vector<pii>> (n + 1);
    for (int i = 0; i < n - 1 ; i++) {
        int v, u, d;
        cin >> v >> u >> d;

        adjList[v].push_back({ u, d });
        adjList[u].push_back({ v, d });
    }

    isLeaf = vector<bool> (n + 1, false);
    for (int i = 1; i <= n; i++)
        if (adjList[i].size() == 1)
            isLeaf[i] = true;
    
    for (int i = 1; i <= n; i++)
        if (isLeaf[i])
            dfs(i, 0, 0);

    cout << ans << '\n';

    return 0;
}
// Baekjoon13265.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int colors[1'001];
vector<int> adjList[1'001];

bool dfs(int curr, int color) {
    for (int& adj : adjList[curr]) {
        if (colors[adj] == 0) {
            colors[adj] = color * -1;
            if (dfs(adj, color * -1) == false)
                return false;
        } else if (colors[adj] == color) {
            return false;
        }
    }

    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int ans = true;
    for (int i = 1; i <= n; i++) {
        if (colors[i] == 0) {
            colors[i] = 1;
            ans = ans & dfs(i, 1);
        }
    }

    cout << (ans ? "possible" : "impossible") << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        fill(colors, colors + 1'001, 0);
        for (int i = 0; i < 1'001; i++)
            adjList[i].clear();

        solve();
    }

    return 0;
}
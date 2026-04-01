// Baekjoon24482.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int height[100'001];
vector<int> adjList[100'001];

void dfs(int curr, int h) {
    height[curr] = h;
    for (int& a : adjList[curr]) {
        if (height[a] == -1)
            dfs(a, h + 1);
    }
}

int main(void) {
    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        height[i] = -1;
        sort(adjList[i].begin(), adjList[i].end(), greater<int>());
    }

    dfs(r, 0);

    for (int i = 1; i <= n; i++)
        cout << height[i] << '\n';

    return 0;
}

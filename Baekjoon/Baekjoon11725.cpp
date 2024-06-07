// Baekjoon11725.cpp
#include <iostream>

#include <vector>

using namespace std;

vector<int> parents;
vector<vector<int>> adjList;

void dfs(int me, int mom) {
    parents[me] = mom;

    for (int& adj : adjList[me]) {
        if (adj != mom)
            dfs(adj, me);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    parents = vector<int> (n + 1, 0);
    adjList = vector<vector<int>> (n + 1);

    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        adjList[v].push_back(u);
        adjList[u].push_back(v);
    }

    dfs(1, 0);

    for (int i = 2; i <= n; i++)
        cout << parents[i] << '\n';

    return 0;
}
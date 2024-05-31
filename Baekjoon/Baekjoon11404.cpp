// Baekjoon11404.cpp
#include <iostream>

#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjMat(n + 1, vector<int> (n + 1, INF));
    for (int i = 0; i < m; i++) {
        int v, u, cost;
        cin >> v >> u >> cost;

        adjMat[v][u] = min(adjMat[v][u], cost);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    adjMat[i][j] = min(min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]), INF);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << (adjMat[i][j] != INF ? adjMat[i][j] : 0) << ' ';
        cout << '\n';
    }

    return 0;
}
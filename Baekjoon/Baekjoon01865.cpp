// Baekjoon01865.cpp
#include <iostream>

#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

struct Edge {
    int vertex1, vertex2, cost;
    Edge(): vertex1(0), vertex2(0), cost(0) { }
};

void solve() {
    int n, m, w;
    cin >> n >> m >> w;

    vector<Edge> edges(2 * m + w);
    for (int i = 0; i < 2 * m; i += 2) {
        cin >> edges[i].vertex1 >> edges[i].vertex2 >> edges[i].cost;

        edges[i + 1].vertex2 = edges[i].vertex1;
        edges[i + 1].vertex1 = edges[i].vertex2;
        edges[i + 1].cost = edges[i].cost;
    }

    for (int i = 2 * m; i < 2 * m + w; i++) {
        cin >> edges[i].vertex1 >> edges[i].vertex2 >> edges[i].cost;
        edges[i].cost *= -1;
    }

    vector<int> shortest(n + 1, INF);
    shortest[1] = 0;
    for (int i = 0; i < n - 1; i++)
        for (Edge& edge : edges)
            shortest[edge.vertex2] = min(shortest[edge.vertex2], shortest[edge.vertex1] + edge.cost);


    bool hasNegative = false;
    for (Edge& edge : edges) {
        if (shortest[edge.vertex2] > shortest[edge.vertex1] + edge.cost) {
            hasNegative = true;
            break;
        }
    }

    cout << (hasNegative ? "YES" : "NO") << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
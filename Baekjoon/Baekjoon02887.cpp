// Baekjoon02887.cpp
#include <iostream>

#include <vector>
#include <algorithm>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct Edge {
    int u, v, cost;
    Edge(int u, int v, int c): u(u), v(v), cost(c) { }

    bool operator<(const Edge& e2) const {
        return cost < e2.cost;
    }
};

int parent[100'000];

int find(int target) {
    return parent[target] = (parent[target] == target ? target : find(parent[target]));
}

void unite(int a, int b) {
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int n;
    cin >> n;

    pii position[3][100'000];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> position[j][i].first;
            position[j][i].second = i;
        }
    }

    for (int i = 0; i < 3; i++)
        sort(position[i], position[i] + n);

    vector<Edge> edges;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            pii prev = position[j][i - 1], curr = position[j][i];
            edges.push_back(Edge(curr.second, prev.second, ABS(curr.first - prev.first)));
        }
    }

    sort(edges.begin(), edges.end());

    int visited = 0;
    ll ans = 0LL;
    for (int i = 0; visited < n - 1; i++) {
        Edge curr = edges[i];

        int root1 = find(curr.u), root2 = find(curr.v);
        if (root1 != root2) {
            unite(root1, root2);
            ans = ans + curr.cost;
            visited++;
        }
    }

    cout << ans << '\n';

    return 0;
}

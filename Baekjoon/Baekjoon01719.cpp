// Baekjoon01719.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct Node {
    int vertex, cost, from;
    Node(int v, int c): vertex(v), cost(c), from(0) { }
    Node(int v, int f, int c): vertex(v), cost(c), from(f) { }

    bool operator<(const Node& n2) const {
        return cost > n2.cost;
    }
};

int ans[201][201];
vector<Node> adjList[201];

void dijkstra(int start) {
    priority_queue<Node> pq;
    bool visited[201] = { false, };

    visited[start] = true;
    for (Node& adjV : adjList[start])
        pq.push(Node(adjV.vertex, adjV.cost));

    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (!visited[curr.vertex]) {
            visited[curr.vertex] = true;

            if (curr.from == 0)
                curr.from = curr.vertex;
            ans[start][curr.vertex] = curr.from;
            for (Node& adjV : adjList[curr.vertex]) {
                if (!visited[adjV.vertex]) {
                    pq.push(Node(adjV.vertex, curr.from, curr.cost + adjV.cost));
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        adjList[u].push_back(Node(v, c));
        adjList[v].push_back(Node(u, c));
    }

    for (int i = 1; i <= n; i++)
        dijkstra(i);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j])
                cout << ans[i][j];
            else
                cout << '-';
            cout << ' ';
        }
        cout << endl;
    }

    return 0;
}

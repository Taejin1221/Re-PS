// Baekjoon01753.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct Node {
    int vertex, distance;
    Node(int v, int d): vertex(v), distance(d) { }
    bool operator<(const Node& n2) const {
        return distance > n2.distance;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int start;
    cin >> start;

    vector<vector<Node>> adjList(n + 1);
    for (int i = 0; i < m; i++) {
        int v, u, d;
        cin >> v >> u >> d;

        adjList[v].push_back(Node(u, d));
    }

    priority_queue<Node> pq;
    vector<int> visited(n + 1, -1);

    pq.push(Node(start, 0));
    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (visited[curr.vertex] == -1) {
            visited[curr.vertex] = curr.distance;

            for (Node& adj : adjList[curr.vertex])
                if (visited[adj.vertex] == -1)
                    pq.push(Node(adj.vertex, curr.distance + adj.distance));
        }
    }

    for (int i = 1; i <= n; i++){
        if (visited[i] == -1)
            cout << "INF";
        else
            cout << visited[i];
        cout << '\n';
    }

    return 0;    
}
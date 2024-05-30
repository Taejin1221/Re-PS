// Baekjoon01238.cpp
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

int getShortestPath(vector<vector<Node>>& adjList, int source, int destination) {
    priority_queue<Node> pq;
    vector<bool> visited(adjList.size() + 1);

    pq.push(Node(source, 0));
    while (pq.top().vertex != destination) {
        Node curr = pq.top(); pq.pop();

        if (!visited[curr.vertex]) {
            visited[curr.vertex] = true;
            
            for (Node& adj : adjList[curr.vertex])
                if (!visited[adj.vertex])
                    pq.push(Node(adj.vertex, curr.distance + adj.distance));
        }
    }

    return pq.top().distance;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<Node>> adjList(n + 1);
    for (int i = 0; i < m; i++) {
        int v, u, d;
        cin >> v >> u >> d;

        adjList[v].push_back(Node(u, d));
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, getShortestPath(adjList, i, x) + getShortestPath(adjList, x, i));

    cout << ans << '\n';

    return 0;
}
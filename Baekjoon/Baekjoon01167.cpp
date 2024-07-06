// Baekjoon01167.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;

struct Node {
    int vertex, distance;
    Node(int v, int d): vertex(v), distance(d) { }
};

vector<Node> adjList[100'001];

pii getFarthestNode(int start) {
    pii result = { 0, 0 };

    queue<Node> q;
    bool visited[100'001] = { false, };

    q.push(Node(start, 0));
    visited[start] = true;

    while (!q.empty()) {
        Node curr = q.front(); q.pop();

        if (result.second < curr.distance)
            result = { curr.vertex, curr.distance };

        for (Node& adj : adjList[curr.vertex]) {
            if (!visited[adj.vertex]) {
                visited[adj.vertex] = true;

                q.push(Node(adj.vertex, curr.distance + adj.distance));
            }
        }
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int me;
        cin >> me;

        int vertex;
        cin >> vertex;
        while (vertex != -1) {
            int distance;
            cin >> distance;

            adjList[me].push_back(Node(vertex, distance));

            cin >> vertex;
        }
    }

    pii firstFar = getFarthestNode(1);
    pii ans = getFarthestNode(firstFar.first);

    cout << ans.second << '\n';

    return 0;
}
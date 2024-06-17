// Baekjoon14221.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;

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

    vector<Node> adjList[5'001];
    for (int i = 0; i < m; i++) {
        int v, u, d;
        cin >> v >> u >> d;

        adjList[v].push_back(Node(u, d));
        adjList[u].push_back(Node(v, d));
    }

    int homeN, storeN;
    cin >> homeN >> storeN;

    bool isHome[5'001] = { false, };
    for (int i = 0; i < homeN; i++) {
        int home;
        cin >> home;

        isHome[home] = true;
    }

    priority_queue<Node> pq;
    for (int i = 0; i < storeN; i++) {
        int store;
        cin >> store;

        pq.push(Node(store, 0));
    }

    pii ans = { 0, 0x3f3f3f3f }; // { vertex, distnace };
    bool visited[5'001] = { false, };
    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (!visited[curr.vertex]) {
            visited[curr.vertex] = true;

            if (isHome[curr.vertex]) {
                if (ans.second == curr.distance)
                    ans.first = min(ans.first, curr.vertex);
                else if (ans.second > curr.distance)
                    ans = { curr.vertex, curr.distance };
            }

            for (Node& adj : adjList[curr.vertex])
                if (!visited[adj.vertex])
                    pq.push(Node(adj.vertex, curr.distance + adj.distance));
        }
    }

    cout << ans.first << '\n';

    return 0;
}
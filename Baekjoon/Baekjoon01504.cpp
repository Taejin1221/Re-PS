// Baekjoon01504.cpp
#include <iostream>

#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int num, distance;
    Node(int n, int d): num(n), distance(d) { }

    bool operator<(const Node& n2) const {
        return distance > n2.distance;
    }
};

vector<Node> adjList[801];

int getShortestPath(int start, int end) {
    priority_queue<Node> pq;
    bool visited[801] = { false, };
    
    pq.push(Node(start, 0));
    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (curr.num == end)
            return curr.distance;

        if (!visited[curr.num]) {
            visited[curr.num] = true;

            for (Node& adj : adjList[curr.num])
                if (!visited[adj.num])
                    pq.push(Node(adj.num, adj.distance + curr.distance));
        }
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adjList[a].push_back(Node(b, c));
        adjList[b].push_back(Node(a, c));
    }

    int v1, v2;
    cin >> v1 >> v2;

    int start_v1 = getShortestPath(1, v1);
    int v1_v2 = getShortestPath(v1, v2);
    int v2_end = getShortestPath(v2, n);

    int start_v2 = getShortestPath(1, v2);
    int v2_v1 = getShortestPath(v2, v1);
    int v1_end = getShortestPath(v1, n);

    int ans;
    if (start_v1 == -1 || v1_v2 == -1 || v2_end == -1)
        ans = 0x3f3f3f3f;
    else
        ans = start_v1 + v1_v2 + v2_end;

    if (start_v2 == -1 || v2_v1 == -1 || v1_end == -1) {
        if (ans == 0x3f3f3f3f)
            ans = -1;        
    } else
        ans = min(ans, start_v2 + v2_v1 + v1_end);

    cout << ans << '\n';

    return 0;
}
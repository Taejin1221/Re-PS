// Baekjoon01916.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct Node {
    int num, cost;
    Node(int n, int c): num(n), cost(c) { }

    bool operator<(const Node& n2) const {
        return cost > n2.cost;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Node> adjList[1'001];
    for (int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;

        adjList[s].push_back(Node(e, c));
    }

    int start, end;
    cin >> start >> end;

    priority_queue<Node> pq;
    bool visited[1'001] = { false, };

    pq.push(Node(start, 0));

    int ans;
    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (curr.num == end) {
            ans = curr.cost;
            break;
        }

        if (!visited[curr.num]) {
            visited[curr.num] = true;

            for (Node& adj : adjList[curr.num])
                if (!visited[adj.num])
                    pq.push(Node(adj.num, curr.cost + adj.cost));
        }
    }

    cout << ans << '\n';

    return 0;
}
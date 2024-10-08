// Baekjoon01647.cpp
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

    vector<Node> adjList[100'001];
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        adjList[u].push_back(Node(v, d));
        adjList[v].push_back(Node(u, d));
    }

    priority_queue<Node> pq;
    bool visited[100'001] = { false, };

    pq.push(Node(1, 0));
    int visitedNum = 0, ans = 0, maxCost = 0;
    while (!pq.empty() && visitedNum < n) {
        Node curr = pq.top(); pq.pop();

        if (!visited[curr.num]) {
            ans += curr.cost;
            maxCost = max(maxCost, curr.cost);

            visited[curr.num] = true;
            visitedNum++;

            for (Node& adjV : adjList[curr.num]) {
                if (!visited[adjV.num])
                    pq.push(adjV);
            }
        }
    }

    cout << ans - maxCost << '\n';

    return 0;
}
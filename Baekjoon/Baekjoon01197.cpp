// Baekjoon01197.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct Node {
    int num, weight;

    Node(int n, int w): num(n), weight(w) { }

    bool operator<(const Node& n2) const {
        return weight > n2.weight;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;

    vector<Node> adjList[10'001];
    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        
        adjList[a].push_back(Node(b, w));
        adjList[b].push_back(Node(a, w));
    }

    priority_queue<Node> pq;
    bool visited[10'001] = { false, };
    
    long long ans = 0LL;
    pq.push(Node(1, 0));
    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (!visited[curr.num]) {
            visited[curr.num] = true;
            ans = ans + curr.weight;

            for (Node& adj : adjList[curr.num])
                if (!visited[adj.num])
                    pq.push(Node(adj.num, adj.weight));
        }
    }

    cout << ans << '\n';

    return 0;
}
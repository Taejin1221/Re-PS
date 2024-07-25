// Baekjoon14938.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct Node {
    int num, distance;

    Node(int n, int d): num(n), distance(d) { }
    bool operator<(const Node& n2) const {
        return distance > n2.distance;
    }
};

int getMaxItem(vector<Node> adjList[], int items[], int start, int range) {
    priority_queue<Node> pq;
    bool visited[101] = { false, };

    pq.push(Node(start, 0));

    int result = 0;
    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (curr.distance > range)
            return result;

        if (!visited[curr.num]) {
            visited[curr.num] = true;
            result += items[curr.num];

            for (Node& adj : adjList[curr.num])
                if (!visited[adj.num])
                    pq.push(Node(adj.num, adj.distance + curr.distance));
        }
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    
    int items[101];
    for (int i = 1; i <= n; i++)
        cin >> items[i];
    
    vector<Node> adjList[101];
    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;

        adjList[a].push_back(Node(b, l));
        adjList[b].push_back(Node(a, l));
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, getMaxItem(adjList, items, i, m));
    
    cout << ans << '\n';
    
    return 0;
}
// Baekjoon11779.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct Node {
    int curr, past, distance;
    Node(int c, int d): curr(c), distance(d) { }
    Node(int c, int p, int d): curr(c), past(p), distance(d) { }
    bool operator<(const Node& n2) const {
        return distance > n2.distance;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Node> adjList[1'001];
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        adjList[u].push_back(Node(v, c));
    }

    int start, end;
    cin >> start >> end;

    priority_queue<Node> pq;
    int path[1'001] = { 0, };

    int ans;
    pq.push(Node(start, -1, 0));
    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (curr.curr == end) {
            ans = curr.distance;
            path[curr.curr] = curr.past;
            break;
        }

        if (path[curr.curr] == 0) {
            path[curr.curr] = curr.past;

            for (Node& adj : adjList[curr.curr]) {
                if (path[adj.curr] == 0)
                    pq.push(Node(adj.curr, curr.curr, curr.distance + adj.distance));
            }
        }
    }

    vector<int> ansPath;
    for (int i = end; i != -1; i = path[i])
        ansPath.push_back(i);

    cout << ans << '\n';
    cout << ansPath.size() << '\n';
    for (auto iter = ansPath.rbegin(); iter != ansPath.rend(); ++iter)
        cout << *iter << ' ';
    cout << '\n';

    return 0;
}
// Baekjoon17396.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using ll = long long;

struct Node {
    int num;
    ll cost;

    Node(int n, ll c): num(n), cost(c) { }

    bool operator<(const Node& n2) const {
        return cost > n2.cost;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    bool canSee[100'000] = { false, };
    for (int i = 0; i < n; i++)
        cin >> canSee[i];

    vector<Node> adjList[100'000];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if ((a == n - 1 || !canSee[a]) && (b == n - 1 || !canSee[b])) {
            adjList[a].push_back(Node(b, (ll)c));
            adjList[b].push_back(Node(a, (ll)c));
        }
    }

    priority_queue<Node> pq;
    bool visited[100'000] = { false, };

    pq.push(Node(0, 0));

    ll ans = -1;
    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (curr.num == n - 1) {
            ans = curr.cost;
            break;
        }

        if (!visited[curr.num]) {
            visited[curr.num] = true;
            for (Node& adjV : adjList[curr.num])
                if (!visited[adjV.num])
                    pq.push(Node(adjV.num, curr.cost + adjV.cost));
        }
    }

    cout << ans << '\n';

    return 0;
}

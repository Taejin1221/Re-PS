// Baekjoon01005.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct Node {
    int num, second;
    Node(int n, int s): num(n), second(s) { }

    bool operator<(const Node& n2) const {
        return second > n2.second;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    int delay[1'001];
    for (int i = 1; i <= n; i++)
        cin >> delay[i];

    int indegree[1'001] = { 0, };
    vector<int> adjList[1'001];
    for (int i = 0; i < k; i++) {
        int start, target;
        cin >> start >> target;

        adjList[start].push_back(target);
        indegree[target]++;
    }

    int target;
    cin >> target;

    int endTime[1'001] = { 0, };
    priority_queue<Node> pq;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            endTime[i] = delay[i];
            pq.push(Node(i, delay[i]));
        }
    }

    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();
        if (curr.num == target)
            break;

        for (int adj : adjList[curr.num]) {
            if (--indegree[adj] == 0) {
                endTime[adj] = endTime[curr.num] + delay[adj];
                pq.push(Node(adj, endTime[adj]));
            }
        }
    }

    cout << endTime[target] << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
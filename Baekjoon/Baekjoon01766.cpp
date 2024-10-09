// Baekjoon01766.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int indegree[32'001] = { 0, };
    vector<int> adjList[32'001];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adjList[a].push_back(b);
        indegree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            pq.push(i);

    while (!pq.empty()) {
        int curr = pq.top(); pq.pop();
        cout << curr << ' ';

        for (int& adjV : adjList[curr]) {
            if (--indegree[adjV] == 0)
                pq.push(adjV);
        }
    }
    cout << '\n';

    return 0;
}
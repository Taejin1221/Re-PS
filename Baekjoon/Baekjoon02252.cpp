// Baekjoon02252.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

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

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!indegree[i])
            q.push(i);

    while (!q.empty()) {
        int curr = q.front(); q.pop();

        cout << curr << ' ';

        for (int& adjV : adjList[curr]) {
            if (--indegree[adjV] == 0)
                q.push(adjV);
        }
    }

    cout << '\n';

    return 0;
}
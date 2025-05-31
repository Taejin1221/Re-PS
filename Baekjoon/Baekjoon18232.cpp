// Baekjoon18232.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int s, e;
    cin >> s >> e;

    vector<int> adjList[300'001];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    queue<pii> q;
    bool visited[300'001] = { false, };

    q.push({ s, 0 });
    visited[s] = true;

    int ans = -1;
    while (!q.empty()) {
        pii curr = q.front(); q.pop();

        if (curr.first == e) {
            ans = curr.second;
            break;
        }

        int nextPos = curr.first + 1, nextTime = curr.second + 1;
        if (nextPos <= n && !visited[nextPos]) {
            visited[nextPos] = true;
            q.push({ nextPos, nextTime });
        }

        nextPos = curr.first - 1;
        if (0 <= nextPos && !visited[nextPos]) {
            visited[nextPos] = true;
            q.push({ nextPos, nextTime });
        }

        for (int& adjV : adjList[curr.first]) {
            if (!visited[adjV]) {
                visited[adjV] = true;
                q.push({ adjV, nextTime });
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

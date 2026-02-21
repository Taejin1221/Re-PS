// Baekjoon01707.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

void solve() {
    int v, e;
    cin >> v >> e;

    vector<int> adjList[20'001];
    for (int i = 0; i < e; i++) {
        int v, e;
        cin >> v >> e;

        adjList[v].push_back(e);
        adjList[e].push_back(v);
    }

    bool ans = true;
    int team[20'001] = { 0, };
    for (int i = 1; ans && i <= v; i++) {
        if (team[i] != 0)
            continue;

        queue<int> q;

        q.push(i);
        team[i] = 1;

        while (ans && !q.empty()) {
            int curr = q.front(); q.pop();

            for (int& adj : adjList[curr]) {
                if (team[adj] == 0) {
                    team[adj] = team[curr] * -1;
                    q.push(adj);
                } else if (team[adj] == team[curr]) {
                    ans = false;
                    break;
                }
            }
        }
    }


    cout << (ans ? "YES" : "NO") << '\n';

    return;
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

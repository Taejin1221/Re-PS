// Baekjoon02660.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;

int getScores(vector<int> adjList[], int start) {
    queue<pii> q;
    bool visited[51] = { false, };

    q.push({ start, 0 });
    visited[start] = true;

    int result = 0;
    while (!q.empty()) {
        pii curr = q.front(); q.pop();
        result = max(result, curr.second);

        for (int& adjV : adjList[curr.first]) {
            if (!visited[adjV]) {
                visited[adjV] = true;
                q.push({ adjV, curr.second + 1 });
            }
        }
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> adjList[51];

    int u, v;
    cin >> u >> v;
    while (!(u == -1 && v == -1)) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);

        cin >> u >> v;
    }

    int bossScore = 100;
    int scores[51] = { 0, };
    for (int i = 1; i <= n; i++)  {
        scores[i] = getScores(adjList, i);
        bossScore = min(bossScore, scores[i]);
    }

    vector<int> boss;
    for (int i = 1; i <= n; i++)
        if (scores[i] == bossScore)
            boss.push_back(i);

    cout << bossScore << ' ' << boss.size() << '\n';
    for (int i = 0; i < boss.size(); i++)
        cout << boss[i] << ' ';
    cout << '\n';

    return 0;
}
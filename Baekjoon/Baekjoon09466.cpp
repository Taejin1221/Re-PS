// Baekjoon09466.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

vector<int> stck;
int teamNum, teamInfo[100'001];
int adjList[100'001];
bool visited[100'001];

void dfs(int curr) {
    visited[curr] = true;
    stck.push_back(curr);

    int next = adjList[curr];
    if (!visited[next])
        dfs(next);
    else {
        int nextIdx = 0;
        for (nextIdx = 0; nextIdx < stck.size() && stck[nextIdx] != next; nextIdx++);
        if (nextIdx <= stck.size()) {
            for (; nextIdx < stck.size(); nextIdx++)
                teamInfo[stck[nextIdx]] = teamNum;
            teamNum++;
        }
    }

    stck.pop_back();
}

void solve() {
    int n;
    cin >> n;

    teamNum = 1;
    fill(visited, visited + n + 1, false);
    fill(teamInfo, teamInfo + n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> adjList[i];

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!teamInfo[i])
            ans++;

    cout << ans << '\n';
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
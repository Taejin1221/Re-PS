// Baekjoon09328.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;

const pii moves[4] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

void solve() {
    int n, m;
    cin >> n >> m;

    char building[100][101];
    for (int i = 0; i < n; i++)
        cin >> building[i];

    int keys[26] = { false, };

    char temp[100];
    cin >> temp;

    for (int i = 0; temp[i] && temp[i] != '0'; i++)
        keys[temp[i] - 'a'] = true;

    queue<pii> q;
    bool visited[100][100] = { { false, }, };

    for (int i = 0; i < m; i++) {
        if (building[0][i] != '*') {
            visited[0][i] = true;
            q.push({ 0, i });
        }
    }

    for (int i = 1; i < n; i++) {
        if (building[i][0] != '*') {
            visited[i][0] = true;
            q.push({ i, 0 });
        }
    }

    for (int i = 1; i < n; i++) {
        if (building[i][m - 1] != '*') {
            visited[i][m - 1] = true;
            q.push({ i, m - 1 });
        }
    }

    for (int i = 1; i < m - 1; i++) {
        if (building[n - 1][i] != '*') {
            visited[n - 1][i] = true;
            q.push({ n - 1, i });
        }
    }

    int ans = 0;
    vector<pii> lazy[26];
    while (!q.empty()) {
        int currRow = q.front().first, currCol = q.front().second; q.pop();

        int curr = building[currRow][currCol];
        if (curr == '$')
            ans++;
        else if ('a' <= curr && curr <= 'z') {
            int idx = curr - 'a';
            keys[idx] = true;
            while (lazy[idx].size()) {
                pii back = lazy[idx].back();
                q.push({ back.first, back.second });
                lazy[idx].pop_back();
            }
        } else if ('A' <= curr && curr <= 'Z') {
            if (!keys[curr - 'A']) {
                lazy[curr - 'A'].push_back({ currRow, currCol });
                continue;
            }
        } else if (curr == '*')
            continue;

        for (int i = 0; i < 4; i++) {
            int nextRow = currRow + moves[i].first, nextCol = currCol + moves[i].second;

            if ((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < m)) {
                if (!visited[nextRow][nextCol]) {
                    visited[nextRow][nextCol] = true;
                    q.push({ nextRow, nextCol });
                }
            }
        }
    }

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

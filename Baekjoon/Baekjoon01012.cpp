// Baekjoon01012.cpp
#include <iostream>

#include <queue>
#include <vector>

#define ROW first
#define COL second

using namespace std;

using pii = pair<int, int>;

pii moves[4] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

void solve() {
    int n, m, k;
    cin >> m >> n >> k;

    vector<vector<int>> farm(n, vector<int> (m));
    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> col >> row;

        farm[row][col] = 1;
    }

    int ans = 0;
    vector<vector<bool>> visited(n, vector<bool> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                if (farm[i][j] == 1) {
                    queue<pii> q;
                    q.push({ i, j });

                    while (!q.empty()) {
                        pii curr = q.front(); q.pop();

                        for (pii& move : moves) {
                            int newRow = curr.ROW + move.ROW, newCol = curr.COL + move.COL;
                            if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
                                if (!visited[newRow][newCol] && farm[newRow][newCol] == 1) {
                                    visited[newRow][newCol] = true;
                                    q.push({ newRow, newCol });
                                }
                            }
                        }
                    }

                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
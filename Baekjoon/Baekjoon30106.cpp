#include <iostream>

#include <queue>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

using pii = pair<int, int>;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, l;
    cin >> n >> m >> l;

    int home[500][500];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> home[i][j];

    int ans = 0;
    bool visited[500][500] = { { false, }, };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j])
                continue;

            queue<pii> q;
            q.push({ i, j });
            visited[i][j] = true;

            while (!q.empty()) {
                pii curr = q.front(); q.pop();
                int r = curr.first, c = curr.second;

                for (int k = 0; k < 4; k++) {
                    int nr = r + moves[k][0], nc = c + moves[k][1];
                    if ((0 <= nr && nr < n) && (0 <= nc && nc < m)) {
                        if (!visited[nr][nc] && ABS(home[r][c] - home[nr][nc]) <= l) {
                            visited[nr][nc] = true;
                            q.push({ nr, nc });
                        }
                    }
                }
            }

            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}

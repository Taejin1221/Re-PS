// Baekjoon28471.cpp
#include <iostream>

#include <queue>

using namespace std;

using pii = pair<int, int>;

const pii moves[7] = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    pii start = { 0, 0 };
    char board[2'000][2'001];
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < n; j++)
            if (board[i][j] == 'F')
                start = { i, j };
    }

    queue<pii> q;
    bool visited[2'000][2'000] = { { false, }, };

    q.push(start);
    visited[start.first][start.second] = true;

    int ans = 0;
    while (!q.empty()) {
        pii curr = q.front(); q.pop();

        for (int i = 0; i < 7; i++) {
            int nextR = curr.first + moves[i].first, nextC = curr.second + moves[i].second;
            if ((0 <= nextR && nextR < n) && (0 <= nextC && nextC < n)) {
                if (!visited[nextR][nextC] && board[nextR][nextC] == '.') {
                    visited[nextR][nextC] = true;
                    ans++;
                    q.push({ nextR, nextC });
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

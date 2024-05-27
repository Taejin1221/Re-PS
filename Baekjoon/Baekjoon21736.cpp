// Baekjoon21736.cpp
#include <iostream>

#include <queue>

#define R first
#define C second

using namespace std;

using pii = pair<int, int>;

const pii moves[4] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pii doyeon;
    char campus[600][601];
    for (int i = 0; i < n; i++) {
        cin >> campus[i];

        for (int j = 0; j < m; j++)
            if (campus[i][j] == 'I')
                doyeon = { i, j };
    }

    queue<pii> q;
    bool visited[600][601] = { { false, } };

    q.push(doyeon);
    visited[doyeon.R][doyeon.C] = true;

    int ans = 0;
    while (!q.empty()) {
        pii curr = q.front(); q.pop();
        if (campus[curr.R][curr.C] == 'P')
            ans++;

        for (int i = 0; i < 4; i++) {
            int newRow = curr.R + moves[i].R, newCol = curr.C + moves[i].C;
            if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
                if (!visited[newRow][newCol] && campus[newRow][newCol] != 'X') {
                    visited[newRow][newCol] = true;
                    q.push({ newRow, newCol });
                }
            }
        }
    }

    if (ans == 0)
        cout << "TT";
    else
        cout << ans;
    cout << '\n';

    return 0;
}
// Baekjoon07562.cpp
#include <iostream>

#include <queue>

using namespace std;

using pii = pair<int, int>;

struct Position {
    int row, col, time;

    Position(pii p, int t): row(p.first), col(p.second), time(t) { }
};

const int moves[8][2] = {
    { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 },
    { 1, 2 }, { 2, 1 }, { 2, -1 }, { 1, -2 }
};

void solve() {
    int n;
    cin >> n;

    pii start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    queue<Position> q;
    bool visited[300][300] = { { false, } , };

    q.push(Position(start, 0));
    visited[start.first][start.second] = true;
    while (!q.empty()) {
        Position curr = q.front(); q.pop();

        if (curr.row == end.first && curr.col == end.second) {
            cout << curr.time << '\n';

            return;
        }

        for (int i = 0; i < 8; i++) {
            int newRow = curr.row + moves[i][0], newCol = curr.col + moves[i][1];
            if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < n)) {
                if (!visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    q.push(Position({ newRow, newCol }, curr.time + 1));
                }
            }
        }
    }

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

// Baekjoon02206.cpp
#include <iostream>

#include <queue>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

struct Node {
    int row, col, time;
    bool isBreak;
    Node(int r, int c, int t, bool b): row(r), col(c), time(t), isBreak(b) { }
};

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char> (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    queue<Node> q;
    vector<vector<bool>> visited[2] = { vector<vector<bool>> (n, vector<bool> (m, false)), vector<vector<bool>> (n, vector<bool> (m, false)) };

    q.push(Node(0, 0, 1, true));
    visited[1][0][0] = true;

    int result[2] = { INF, INF };
    while (!q.empty()) {
        Node curr = q.front(); q.pop();
        if (curr.row == n - 1 && curr.col == m - 1)
            result[curr.isBreak] = min(result[curr.isBreak], curr.time);

        for (int i = 0; i < 4; i++) {
            int newRow = curr.row + moves[i][0], newCol = curr.col + moves[i][1];
            if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
                if ((map[newRow][newCol] == '1' && curr.isBreak) && !visited[1][newRow][newCol]) {
                    visited[1][newRow][newCol] = true;
                    q.push(Node(newRow, newCol, curr.time + 1, false));
                }

                if (map[newRow][newCol] == '0' && !visited[curr.isBreak][newRow][newCol]) {
                    visited[curr.isBreak][newRow][newCol] = true;
                    q.push(Node(newRow, newCol, curr.time + 1, curr.isBreak));
                }
            }
        }
    }

    int ans = min(result[0], result[1]);
    cout << (ans != INF ? ans : -1) << '\n';

    return 0;
}
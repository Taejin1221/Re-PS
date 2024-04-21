// Baekjoon02178.cpp
#include <iostream>

#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int row, col, time;

    Node(int r, int c, int t): row(r), col(c), time(t) { }
};

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    for (int i = 0; i < n; i++)
        cin >> maze[i];

    queue<Node> q;
    vector<vector<bool>> visited(n, vector<bool> (m));

    q.push(Node(0, 0, 1));
    visited[0][0] = true;

    int ans;
    while (!q.empty()) {
        Node curr = q.front(); q.pop();
        int row = curr.row, col = curr.col, nextTime = curr.time + 1;

        if (row == n - 1 && col == m - 1) {
            ans = curr.time;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nextRow = row + moves[i][0], nextCol = col + moves[i][1];
            if ((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < m)) {
                if (!visited[nextRow][nextCol] && maze[nextRow][nextCol] == '1') {
                    visited[nextRow][nextCol] = true;
                    q.push(Node(nextRow, nextCol, nextTime));
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
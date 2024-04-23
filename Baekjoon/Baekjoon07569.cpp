// Baekjoon07569.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

const int moves[6][3] = {
    { -1, 0, 0 }, { 1, 0, 0 },
    { 0, -1, 0 }, { 0, 1, 0 },
    { 0, 0, -1 }, { 0, 0, 1 }
};

struct Node {
    int height, row, col, time;
    
    Node(int h, int r, int c, int t): height(h), row(r), col(c), time(t) { }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n, h;
    cin >> m >> n >> h;

    queue<Node> q;
    int notRipen = 0;
    vector<vector<vector<int>>> tomatoes(h, vector<vector<int>> (n, vector<int> (m)));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> tomatoes[i][j][k];

                if (tomatoes[i][j][k] == 1)
                    q.push(Node(i, j, k, 0));
                else if (tomatoes[i][j][k] == 0)
                    notRipen++;
            }
        }
    }

    int ans = -1;
    while (!q.empty()) {
        Node curr = q.front(); q.pop();
        ans = max(ans, curr.time);

        int hi = curr.height, row = curr.row, col = curr.col, nextTime = curr.time + 1;
        for (int i = 0; i < 6; i++) {
            int nextHi = hi + moves[i][0], nextRow = row + moves[i][1], nextCol = col + moves[i][2];
            if ((0 <= nextHi && nextHi < h) && (0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < m)) {
                if (tomatoes[nextHi][nextRow][nextCol] == 0) {
                    tomatoes[nextHi][nextRow][nextCol] = nextTime;
                    notRipen--;

                    q.push(Node(nextHi, nextRow, nextCol, nextTime));
                }
            }
        }
    }

    cout << (notRipen ? -1 : ans) << '\n';

    return 0;
}
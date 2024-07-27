// Baekjoon32031.cpp
#include <iostream>

#include <string>
#include <queue>

using namespace std;

struct Node {
    int layer, row, col;
    Node(int l, int r, int c): layer(l), row(r), col(c) { }
};

const int moves[6][3] = { { 0, -1, 0 }, { 0, 0, 1 }, { 0, 1, 0 }, { 0, 0, -1 }, { -1, 0, 0 }, { 1, 0, 0 } };

int maxMouldRow, maxMouldCol;
int mould[3][600][600];

void bfs(Node start, int gypsum) {
    queue<Node> q;
    q.push(start);

    while (!q.empty()) {
        Node curr = q.front(); q.pop();

        for (int i = 0; i < 6; i++) {
            int nextLayer = curr.layer + moves[i][0], nextRow = curr.row + moves[i][1], nextCol = curr.col + moves[i][2];
            if ((0 <= nextLayer && nextLayer < 3) && (0 <= nextRow && nextRow < maxMouldRow) && (0 <= nextCol && nextCol < maxMouldCol)) {
                int& nextPos = mould[nextLayer][nextRow][nextCol];
                if (nextPos == 0) {
                    nextPos = gypsum;
                    q.push(Node(nextLayer, nextRow, nextCol));
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int maxRow, maxCol;
    cin >> maxRow >> maxCol;

    maxMouldRow = maxRow * 3, maxMouldCol = maxCol * 3;

    string cylinders[200];
    for (int i = 0; i < maxRow; i++) {
        cin >> cylinders[i];
        int row = i * 3;
        for (int j = 0; j < maxCol; j++) {
            int col = j * 3;
            if (cylinders[i][j] == 'O') {
                for (int k = 0; k < 3; k++) {
                    mould[k][row][col + 1] = -1;
                    mould[k][row + 1][col] = -1;
                    mould[k][row + 1][col + 1] = -1;
                    mould[k][row + 1][col + 2] = -1;
                    mould[k][row + 2][col + 1] = -1;
                }
            } else if (cylinders[i][j] == 'I') {
                for (int k = 0; k < 3; k++) {
                    mould[0][row + k][col + 1] = -1;
                    mould[1][row + k][col] = -1;
                    mould[1][row + k][col + 1] = -1;
                    mould[1][row + k][col + 2] = -1;
                    mould[2][row + k][col + 1] = -1;
                }
            } else if (cylinders[i][j] == 'H') {
                for (int k = 0; k < 3; k++) {
                    mould[0][row + 1][col + k] = -1;
                    mould[1][row][col + k] = -1;
                    mould[1][row + 1][col + k] = -1;
                    mould[1][row + 2][col + k] = -1;
                    mould[2][row + 1][col + k] = -1;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < maxMouldRow; j++) {
            for (int k = 0; k < maxMouldCol; k++) {
                if (mould[i][j][k] == 0) {
                    bfs(Node(i, j, k), ans + 1);
                    ans++;
                }
            }
        }
    }

    cout << ans <<'\n';

    return 0;
}
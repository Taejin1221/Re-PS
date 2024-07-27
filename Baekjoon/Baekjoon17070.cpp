// Baekjoon17070.cpp
#include <iostream>

#include <queue>

using namespace std;

struct Node {
    int endRow, endCol, direction;

    Node(int r, int c, int d): endRow(r), endCol(c), direction(d) { }
};

const int moves[3][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 } };

int n, home[16][16];

bool canGo(Node curr, int direction) {
    if (direction == 1) {
        int nextRow = curr.endRow, nextCol = curr.endCol + 1;
        if (!((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < n)) || home[nextRow][nextCol] == 1) {
            return false;
        }
    } else if (direction == 2) {
        for (int i = 0; i < 3; i++) {
            int nextRow = curr.endRow + moves[i][0], nextCol = curr.endCol + moves[i][1];
            if (!((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < n)) || home[nextRow][nextCol] == 1) {
                return false;
            }
        }
    } else if (direction == 3) {
        int nextRow = curr.endRow + 1, nextCol = curr.endCol;
        if (!((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < n)) || home[nextRow][nextCol] == 1) {
            return false;
        }
    }

    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> home[i][j];

    queue<Node> q;
    q.push(Node(0, 1, 1));

    int ans = 0;
    while (!q.empty()) {
        Node curr = q.front(); q.pop();
        if (curr.endRow == n - 1 && curr.endCol == n - 1)
            ans++;
        else {
            if (canGo(curr, 2))
                q.push(Node(curr.endRow + 1, curr.endCol + 1, 2));

            if (curr.direction == 1) {
                if (canGo(curr, 1))
                    q.push(Node(curr.endRow, curr.endCol + 1, 1));
            } else if (curr.direction == 2) {
                if (canGo(curr, 1))
                    q.push(Node(curr.endRow, curr.endCol + 1, 1));
                if (canGo(curr, 3))
                    q.push(Node(curr.endRow + 1, curr.endCol, 3));
            } else {
                if (canGo(curr, 3))
                    q.push(Node(curr.endRow + 1, curr.endCol, 3));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
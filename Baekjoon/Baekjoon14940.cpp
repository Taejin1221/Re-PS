// Baekjoon14940.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

const int moves[4][2] = { { -1, 0, }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

struct Node {
    int row, col, dis;
    Node(int r, int c, int d): row(r), col(c), dis(d) { }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;


    queue<Node> q;
    vector<vector<bool>> visited (n, vector<bool> (m));

    int start[2];
    vector<vector<int>> map (n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 2){
                visited[i][j] = true;
                start[0] = i, start[1] = j;
                q.push(Node(i, j, 0));
            }
        }
    }

    while (!q.empty()) {
        Node curr = q.front(); q.pop();

        int row = curr.row, col = curr.col;
        map[row][col] = curr.dis;

        for (int i = 0; i < 4; i++) {
            int newRow = row + moves[i][0], newCol = col + moves[i][1];
            if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
                if (!visited[newRow][newCol] && map[newRow][newCol] != 0) {
                    visited[newRow][newCol] = true;

                    q.push(Node(newRow, newCol, curr.dis + 1));
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << ((!visited[i][j] && map[i][j] == 1) ? -1 : map[i][j]) << ' ';
        cout << '\n';
    }
}
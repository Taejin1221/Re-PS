// Baekjoon07576.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

struct Node {
    int row, col, time;
    Node(int r, int c, int t): row(r), col(c), time(t) { }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    queue<Node> q;
    vector<vector<int>> tomatoes(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomatoes[i][j];
            if (tomatoes[i][j] == 1)
                q.push(Node(i, j, 0));
        }
    }

    int ans = 0;
    while (!q.empty()) {
        Node curr = q.front(); q.pop();

        ans = max(ans, curr.time);

        for (int i = 0; i < 4; i++) {
            int newRow = curr.row + moves[i][0], newCol = curr.col + moves[i][1];
            if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
                if (tomatoes[newRow][newCol] == 0) {
                    tomatoes[newRow][newCol] = 1;

                    q.push(Node(newRow, newCol, curr.time + 1));
                }
            }
        }
    }

    bool allRipe = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomatoes[i][j] == 0) {
                allRipe = false;
                break;
            }
        }

        if (!allRipe)
            break;
    }

    cout << (allRipe ? ans : -1) << '\n';

    return 0;
}
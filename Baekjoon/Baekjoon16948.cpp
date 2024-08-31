// Baekjoon16948.cpp
#include <iostream>

#include <queue>

using namespace std;

using pii = pair<int, int>;

const int moves[6][2] = { { -2, -1 }, { -2, 1 }, { 0, -2 }, { 0, 2 }, { 2, -1 }, { 2, 1 } };

struct Node {
    int row, col;
    int time;

    Node(int r, int c, int t): row(r), col(c), time(t) { }
};

int main(void) {
    int n;
    cin >> n;

    pii start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    queue<Node> q;
    bool visited[200][200] = { { false, }, };

    q.push(Node(start.first, start.second, 0));
    visited[start.first][start.second] = true;

    int ans = -1;
    while (!q.empty()) {
        Node curr = q.front(); q.pop();
        if (curr.row == end.first && curr.col == end.second) {
            ans = curr.time;
            break;
        }

        for (int i = 0; i < 6; i++) {
            int newRow = curr.row + moves[i][0], newCol = curr.col + moves[i][1];
            if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < n)) {
                if (!visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;

                    q.push(Node(newRow, newCol, curr.time + 1));
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
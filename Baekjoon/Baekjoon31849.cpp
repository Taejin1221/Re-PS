// Baekjoon31849.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

struct Node {
    int row, col, pay;

    Node(): row(0), col(0), pay(0) { }
    Node(int r, int c, int p): row(r), col(c), pay(p) { }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r, c;
    cin >> n >> m >> r >> c;

    vector<Node> homes;
    for (int i = 0; i < r; i++) {
        int row, col, pay;
        cin >> row >> col >> pay;
        row--, col--;

        homes.push_back(Node(row, col, pay));
    }

    queue<Node> q;
    bool visited[1'000][1'000] = { { false, }, };
    for (int i = 0; i < c; i++) {
        int row, col;
        cin >> row >> col;
        row--, col--;

        q.push(Node(row, col, 0));
        visited[row][col] = true;
    }

    int distance[1'000][1'000];
    while (!q.empty()) {
        Node curr = q.front(); q.pop();
        int currRow = curr.row, currCol = curr.col, currDis = curr.pay;

        distance[currRow][currCol] = currDis;

        for (int i = 0; i < 4; i++) {
            int newRow = currRow + moves[i][0], newCol = currCol + moves[i][1];
            if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
                if (!visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    q.push(Node(newRow, newCol, currDis + 1));
                }
            }
        }
    }

    int ans = 0x3f3f3f3f;
    for (Node& home : homes)
        ans = min(ans, distance[home.row][home.col] * home.pay);

    cout << ans << '\n';

    return 0;
}

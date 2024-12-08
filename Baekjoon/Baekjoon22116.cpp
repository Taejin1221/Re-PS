// Baekjoon22116.cpp
#include <iostream>

#include <queue>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

struct Node {
    int row, col, grad;

    Node(int r, int c, int g): row(r), col(c), grad(g) { }
    bool operator<(const Node& n2) const {
        return grad > n2.grad;
    }
};

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
    int n;
    cin >> n;

    int grid[1'000][1'000];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    priority_queue<Node> pq;
    bool visited[1'000][1'000];

    pq.push(Node(0, 0, 0));

    int ans = 0;
    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (curr.row == n - 1 && curr.col == n - 1) {
            ans = curr.grad;
            break;
        }

        if (!visited[curr.row][curr.col]) {
            visited[curr.row][curr.col] = true;

            for (int i = 0; i < 4; i++) {
                int newRow = curr.row + moves[i][0], newCol = curr.col + moves[i][1];
                if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < n))
                    if (!visited[newRow][newCol])
                        pq.push(Node(newRow, newCol, max(curr.grad, ABS(grid[newRow][newCol] - grid[curr.row][curr.col]))));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

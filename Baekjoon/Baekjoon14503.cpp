// Baekjoon14503.cpp
#include <iostream>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

struct Position {
    int row, col, direction;

    void turn() {
        direction = ((direction - 1) + 4) % 4;
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;

    Position curr;
    cin >> curr.row >> curr.col >> curr.direction;

    int home[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> home[i][j];

    int ans = 0;
    while (true) {
        if (home[curr.row][curr.col] == 0) {
            home[curr.row][curr.col] = -1;
            ans++;
        } else {
            bool clean = false;
            for (int i = 0; i < 4; i++) {
                int newRow = curr.row + moves[i][0], newCol = curr.col + moves[i][1];
                if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
                    if (home[newRow][newCol] == 0) {
                        clean = true;
                        break;
                    }
                }
            }

            if (clean) {
                curr.turn();
                int newRow = curr.row + moves[curr.direction][0], newCol = curr.col + moves[curr.direction][1];
                if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
                    if (home[newRow][newCol] == 0)
                        curr.row = newRow, curr.col = newCol;
                }
            } else {
                curr.turn(); curr.turn(); // 후진

                int newRow = curr.row + moves[curr.direction][0], newCol = curr.col + moves[curr.direction][1];
                if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m) && home[newRow][newCol] != 1) {
                    curr.row = newRow, curr.col = newCol;
                    curr.turn(); curr.turn();
                } else {
                    break;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

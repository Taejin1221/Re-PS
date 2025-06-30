// Baekjoon01553.cpp
#include <iostream>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int grid[8][7], ans;
bool domino[7][7], visited[8][7];

void solve(int row, int col) {
    if (row == 8) {
        ans++;
        return;
    }

    if (visited[row][col]) {
        solve(row + (col + 1) / 7, (col + 1) % 7);
        return;
    }

    visited[row][col] = true;
    for (int i = 0; i < 4; i++) {
        int newRow = row + moves[i][0], newCol = col + moves[i][1];
        if ((0 <= newRow && newRow < 8) && (0 <= newCol && newCol < 7)) {
            int small = min(grid[row][col], grid[newRow][newCol]), big = max(grid[row][col], grid[newRow][newCol]);
            if (!domino[small][big] && !visited[newRow][newCol]) {
                domino[small][big] = true;
                visited[newRow][newCol] = true;
                solve(row + (col + 1) / 7, (col + 1) % 7);
                domino[small][big] = false;
                visited[newRow][newCol] = false;
            }
        }
    }
    visited[row][col] = false;

    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            char c;
            cin >> c;

            grid[i][j] = (c - '0');
        }
    }

    solve(0, 0);

    cout << ans << '\n';

    return 0;
}

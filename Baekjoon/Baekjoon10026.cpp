// Baekjoon10026.cpp
#include <iostream>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n;
char grid[2][100][100];
bool visited[2][100][100];

void dfs(int layer, int row, int col, char color) {
    for (int i = 0; i < 4; i++) {
        int newRow = row + moves[i][0], newCol = col + moves[i][1];
        if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < n)) {
            if (!visited[layer][newRow][newCol] && grid[layer][newRow][newCol] == color) {
                visited[layer][newRow][newCol] = true;

                dfs(layer, newRow, newCol, color);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[0][i][j];
            grid[1][i][j] = (grid[0][i][j] == 'B') ? 'B' : 'R';
        }
    }

    int ans[2] = { 0, 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[0][i][j]) {
                visited[0][i][j] = true;
                dfs(0, i, j, grid[0][i][j]);
                ans[0]++;
            }

            if (!visited[1][i][j]) {
                visited[1][i][j] = true;
                dfs(1, i, j, grid[1][i][j]);
                ans[1]++;
            }
        }
    }

    cout << ans[0] << ' ' << ans[1] << '\n';

    return 0;
}
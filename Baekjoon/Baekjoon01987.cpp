// Baekjoon01987.cpp
#include <iostream>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

bool visited[26];
char board[20][21];
int maxRow, maxCol, ans;

void dfs(int row, int col, int curr) {
    ans = max(ans, curr);
    for (int i = 0; i < 4; i++) {
        int nextRow = row + moves[i][0], nextCol = col + moves[i][1];
        if ((0 <= nextRow && nextRow < maxRow) && (0 <= nextCol && nextCol < maxCol)) {
            int idx = board[nextRow][nextCol] - 'A';
            if (!visited[idx]) {
                visited[idx] = true;
                dfs(nextRow, nextCol, curr + 1);
                visited[idx] = false;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> maxRow >> maxCol;

    for (int i = 0; i < maxRow; i++)
        cin >> board[i];

    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << ans << '\n';

    return 0;
}
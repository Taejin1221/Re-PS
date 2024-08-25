// Baekjoon01189.cpp
#include <iostream>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int r, c, k, ans;
char map[5][6];
bool visited[5][5];

void dfs(int currRow, int currCol, int size) {
    if (currRow == 0 && currCol == c - 1 && size == k)
        ans++;
    else {
        for (int i = 0; i < 4; i++) {
            int newRow = currRow + moves[i][0], newCol = currCol + moves[i][1];
            if ((0 <= newRow && newRow < r) && (0 <= newCol && newCol < c)) {
                if (!visited[newRow][newCol] && map[newRow][newCol] != 'T') {
                    visited[newRow][newCol] = true;
                    dfs(newRow, newCol, size + 1);
                    visited[newRow][newCol] = false;
                }
            }
        }
    }
}

int main(void) {
    cin >> r >> c >> k;

    for (int i = 0; i < r; i++)
        cin >> map[i];

    visited[r - 1][0] = true;
    dfs(r - 1, 0, 1);

    cout << ans << '\n';

    return 0;
}
// Baekjoon04963.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int moves[3] = { -1, 0, 1 };

int w, h;
int map[50][50];
bool visited[50][50];

void dfs(int row, int col) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int newRow = row + moves[i], newCol = col + moves[j];
            if ((0 <= newRow && newRow < h) && (0 <= newCol && newCol < w)) {
                if (!visited[newRow][newCol] && map[newRow][newCol] == 1) {
                    visited[newRow][newCol] = true;
                    dfs(newRow, newCol);
                }
            }
        }
    }
}

void solve() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cin >> map[i][j];
        fill(visited[i], visited[i] + w, false);
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                if (map[i][j] == 1) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main(void) {
    cin >> w >> h;

    while (!(w == 0 && h == 0)) {
        solve();
        cin >> w >> h;
    }

    return 0;
}

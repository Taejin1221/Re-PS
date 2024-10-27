// Baekjoon18290.cpp
#include <iostream>

using namespace std;

const int moves[5][2] = { { 0, 0 }, { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m, k, ans = -0x3f3f3f3f;
int grid[10][10], visited[10][10];

void solve(int score, int time) {
    if (time == k)
        ans = max(ans, score);
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool can = true;
                for (int v = 0; v < 5; v++) {
                    int newRow = i + moves[v][0], newCol = j + moves[v][1];
                    if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
                        if (visited[newRow][newCol]) {
                            can = false;
                            break;
                        }
                    }
                }

                if (can) {
                    visited[i][j] = true;
                    solve(score + grid[i][j], time + 1);
                    visited[i][j] = false;
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    solve(0, 0);

    cout << ans << '\n';

    return 0;
}
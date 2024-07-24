// Baekjoon14502.cpp
#include <iostream>

#include <algorithm>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m, lab[8][8], copyLab[8][8];
bool visited[8][8];

void dfs(int row, int col) {
    for (int i = 0; i < 4; i++) {
        int newRow = row + moves[i][0], newCol = col + moves[i][1];
        if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
            if (!visited[newRow][newCol] && copyLab[newRow][newCol] == 0) {
                visited[newRow][newCol] = true;
                copyLab[newRow][newCol] = 2;
                dfs(newRow, newCol);
            }
        }
    }
}

void spread() {
    for (int i = 0; i < n; i++) {
        fill(visited[i], visited[i] + m, false);
        for (int j = 0; j < m; j++)
            copyLab[i][j] = lab[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (copyLab[i][j] == 2 && !visited[i][j]) {
                visited[i][j] = true;
                dfs(i, j);
            }
        }
    }
}

int getSafeArea() {
    int result = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (copyLab[i][j] == 0)
                result++;

    return result;
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> lab[i][j];

    int ans = 0;
    for (int row1 = 0; row1 < n; row1++) {
        for (int col1 = 0; col1 < m; col1++) {
            if (lab[row1][col1] == 0) {
                for (int row2 = 0; row2 < n; row2++) {
                    for (int col2 = 0; col2 < m; col2++) {
                        if (lab[row2][col2] == 0) {
                            for (int row3 = 0; row3 < n; row3++) {
                                for (int col3 = 0; col3 < m; col3++) {
                                    if (lab[row3][col3] == 0) {
                                        if (!((row1 == row2) && (col1 == col2)) && !((row2 == row3) && (col2 == col3)) && !((row3 == row1) && (col3 == col1))) {
                                            lab[row1][col1] = lab[row2][col2] = lab[row3][col3] = 1;
                                            spread();
                                            ans = max(ans, getSafeArea());
                                            lab[row1][col1] = lab[row2][col2] = lab[row3][col3] = 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
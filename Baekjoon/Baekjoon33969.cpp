// Baekjoon33969.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int s_offset[2][11][2] = {
    {
        { 0, 0 }, { 0, 1 }, { 0, 2 },
        { 1, 0 },
        { 2, 0 }, { 2, 1 }, { 2, 2 },
        { 3, 2 },
        { 4, 0 }, { 4, 1 }, { 4, 2 }
    }, {
        { 0, 0 }, { 0, 2 }, { 0, 3 }, { 0, 4 },
        { 1, 0 }, { 1, 2 }, { 1, 4 },
        { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 4 }
    }
};

int c_offset[4][9][2] = {
    {
        { 0, 0 }, { 0, 1 }, { 0, 2 },
        { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 },
        { 4, 1 }, { 4, 2 }
    }, {
        { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 },
        { 1, 0 }, { 1, 4 },
        { 2, 0 }, { 2, 4 }
    }, {
        { 0, 0 }, { 0, 1 }, { 0, 2 },
        { 1, 2 }, { 2, 2 }, { 3, 2 }, { 4, 2 },
        { 4, 0 }, { 4, 1 }
    }, {
        { 0, 0 }, { 0, 4 },
        { 1, 0 }, { 1, 4 },
        { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 2, 4 }
    }
};

int n, m;
pii ans;
char grid[10][11];
bool visited[10][11];

bool solve(int row, int col, int s, int c) {
    if (row >= n) {
        ans = { s, c };
        return true;
    }

    int nextRow = row + (col + 1) / m, nextCol = (col + 1) % m;
    if (grid[row][col] == '.' || visited[row][col])
        return solve(nextRow, nextCol, s, c);

    for (int i = 0; i < 2; i++) {
        bool isS = true;
        for (int j = 0; j < 11; j++) {
            int newRow = row + s_offset[i][j][0], newCol = col + s_offset[i][j][1];
            isS &= ((newRow < n && newCol < m) && !visited[newRow][newCol] && grid[newRow][newCol] == 'x');
        }

        if (isS) {
            for (int j = 0; j < 11; j++) {
                int newRow = row + s_offset[i][j][0], newCol = col + s_offset[i][j][1];
                visited[newRow][newCol] = true;
            }
            if (solve(nextRow, nextCol, s + 1, c))
                return true;
            else {
                for (int j = 0; j < 11; j++) {
                    int newRow = row + s_offset[i][j][0], newCol = col + s_offset[i][j][1];
                    visited[newRow][newCol] = false;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        bool isC = true;
        for (int j = 0; j < 9; j++) {
            int newRow = row + c_offset[i][j][0], newCol = col + c_offset[i][j][1];
            isC &= ((newRow < n && newCol < m) && !visited[newRow][newCol] && grid[newRow][newCol] == 'x');
        }

        if (isC) {
            for (int j = 0; j < 9; j++) {
                int newRow = row + c_offset[i][j][0], newCol = col + c_offset[i][j][1];
                visited[newRow][newCol] = true;
            }
            if (solve(nextRow, nextCol, s, c + 1))
                return true;
            else {
                for (int j = 0; j < 9; j++) {
                    int newRow = row + c_offset[i][j][0], newCol = col + c_offset[i][j][1];
                    visited[newRow][newCol] = false;
                }
            }
        }
    }

    return false;
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> grid[i];

    solve(0, 0, 0, 0);

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}

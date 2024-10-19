// Baekjoon01303.cpp
#include <iostream>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m;
char board[100][101];
bool visited[100][100];

int dfs(int row, int col) {
    int result = 1;
    for (int i = 0; i < 4; i++) {
        int nextRow = row + moves[i][0], nextCol = col + moves[i][1];
        if ((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < m)) {
            if (!visited[nextRow][nextCol] && board[nextRow][nextCol] == board[row][col]) {
                visited[nextRow][nextCol] = true;
                result += dfs(nextRow, nextCol);
            }
        }
    }

    return result;
}

int main(void) {
    cin >> m >> n;

    for (int i = 0; i < n; i++)
        cin >> board[i];

    int teamA = 0LL, teamB = 0LL;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                int result = dfs(i, j);

                if (board[i][j] == 'W')
                    teamA += result * result;
                else
                    teamB += result * result;
            }
        }
    }

    cout << teamA << ' ' << teamB << '\n';

    return 0;
}
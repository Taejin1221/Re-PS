// Baekjoon02210.cpp
#include <iostream>

#include <set>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int ans;
int board[5][5];
set<int> visited;

void dfs(int currRow, int currCol, int size, int num) {
    if (size == 6) {
        if (visited.find(num) == visited.end())
            visited.insert(num);
    } else {
        for (int i = 0; i < 4; i++) {
            int newRow = currRow + moves[i][0], newCol = currCol + moves[i][1];
            if ((0 <= newRow && newRow < 5) && (0 <= newCol && newCol < 5)) {
                dfs(newRow, newCol, size + 1, num * 10 + board[newRow][newCol]);
            }
        }
    }
}

int main(void) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            dfs(i, j, 1, board[i][j]);

    cout << visited.size() << '\n';

    return 0;
}
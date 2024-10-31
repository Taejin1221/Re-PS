// Baekjoon04396.cpp
#include <iostream>

#include <vector>

using namespace std;

const int moves[8][2] = {
    { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }
};

int findMine(vector<vector<char>>& board, int row, int col) {
    int n = board.size();

    int result = 0;
    for (int i = 0; i < 8; i++) {
        int newRow = row + moves[i][0], newCol = col + moves[i][1];
        if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < n)) {
            if (board[newRow][newCol] == '*')
                result++;
        }
    }

    return result;
}

int main(void) {
    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, '\0'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    bool isFail = false;
    vector<vector<char>> ans(n, vector<char>(n, '\0'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ans[i][j];

            if (ans[i][j] == 'x') {
                if (board[i][j] == '*')
                    isFail = true;
                else
                    ans[i][j] = findMine(board, i, j) + '0';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '*' && isFail)
                cout << '*';
            else
                cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}
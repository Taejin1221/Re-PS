// Baekjoon02580.cpp
#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

int board[10][10];
vector<pii> blankPosition;
bool rowTable[10][10], colTable[10][10], squareTable[10][10];

int getSquareNumber(int row, int col) {
    return col / 3 + (row / 3 * 3);
}

bool solve(int idx) {
    if (idx == blankPosition.size())
        return true;
    else {
        int row = blankPosition[idx].first, col = blankPosition[idx].second;
        int squareNumber = getSquareNumber(row, col);
        for (int i = 1; i <= 9; i++) {
            if (!rowTable[row][i] && !colTable[col][i] && !squareTable[squareNumber][i]) {
                rowTable[row][i] = colTable[col][i] = squareTable[squareNumber][i] = true;
                board[row][col] = i;
                if (solve(idx + 1))
                    return true;
                rowTable[row][i] = colTable[col][i] = squareTable[squareNumber][i] = false;
            }
        }

        return false;
    }
}

int main(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];

            if (board[i][j] == 0)
                blankPosition.push_back({ i, j });
            rowTable[i][board[i][j]] = true;
            colTable[j][board[i][j]] = true;
            squareTable[getSquareNumber(i, j)][board[i][j]] = true;
        }
    }

    solve(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
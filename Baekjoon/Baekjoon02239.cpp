// Baekjoon02239.cpp
#include <iostream>

#include <vector>

#define NUM(x, y) (((x) / 3) * 3 + (y) / 3)

using namespace std;

using pii = pair<int, int>;

int board[9][9];
vector<pii> emptyBoard;
bool rowVisited[9][10], colVisited[9][10], squareVisited[9][10];

bool solve(int idx) {
	if (idx == emptyBoard.size())
		return true;

	int row = emptyBoard[idx].first, col = emptyBoard[idx].second;

	for (int i = 1; i <= 9; i++) {
		if (!rowVisited[row][i] && !colVisited[col][i] && !squareVisited[NUM(row, col)][i]) {
			board[row][col] = i;
			rowVisited[row][i] = colVisited[col][i] = squareVisited[NUM(row, col)][i] = true;
			if (solve(idx + 1))
				return true;
			else {
				board[row][col] = 0;
				rowVisited[row][i] = colVisited[col][i] = squareVisited[NUM(row, col)][i] = false;
			}
		}
	}

	return false;
}

int main(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char digit;
			cin >> digit;

			int num = digit - '0';

			board[i][j] = num;
			if (num == 0)
				emptyBoard.push_back({ i, j });
			else
				rowVisited[i][num] = colVisited[j][num] = squareVisited[NUM(i, j)][num] = true;
		}
	}

	solve(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j];
		cout << '\n';
	}

	return 0;
}
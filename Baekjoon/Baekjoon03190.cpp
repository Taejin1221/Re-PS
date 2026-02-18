// Baekjoon03190.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    int n;
    cin >> n;

    int k;
    cin >> k;

    int board[100][100] = { { 0, }, };
    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;

        board[--row][--col] = 1;
    }

    int l;
    cin >> l;

    vector<pii> instruction;
    for (int i = 0; i < l; i++) {
        int sec; char inst;
        cin >> sec >> inst;

        instruction.push_back({ sec, (inst == 'L') ? -1 : 1 });
    }

    int direction = 1, idx = 0, ans = 0;
    queue<pii> snake;

    board[0][0] = 2;
    snake.push({ 0, 0 });
    while (true) {
        if (idx < l && ans == instruction[idx].first) {
            direction += instruction[idx].second;
            direction = (direction + 4) % 4;
            idx++;
        }

        pii head = snake.back();
        int nextRow = head.first + moves[direction][0], nextCol = head.second + moves[direction][1];
        if (!((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < n)) || (board[nextRow][nextCol] == 2))
            break;
        else {
            snake.push({ nextRow, nextCol });
            if (board[nextRow][nextCol] == 0) {
                board[snake.front().first][snake.front().second] = 0;
                snake.pop();
            }
            board[nextRow][nextCol] = 2;
        }

        ans++;
    }

    cout << (ans + 1) << '\n';

    return 0;
}

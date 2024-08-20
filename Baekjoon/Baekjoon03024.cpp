// Baekjoon03024.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    char board[50][50] = { { 0, }, };
    for (int i = 0; i < n; i++)
        cin >> board[i];

    char winner = '\0';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '.') {
                char target = board[i][j];
                if (board[i][j + 1] == target && board[i][j + 2] == target)
                    winner = target;
                else if (board[i + 1][j] == target && board[i + 2][j] == target)
                    winner = target;
                else if (board[i + 1][j + 1] == target && board[i + 2][j + 2] == target)
                    winner = target;
                else if ((j - 1 >= 0 && board[i + 1][j - 1] == target) && (j - 2 >= 0 && board[i + 2][j - 2] == target))
                    winner = target;

                if (winner != '\0')
                    break;
            }
        }

        if (winner != '\0')
            break;
    }

    if (winner == '\0')
        cout << "ongoing";
    else
        cout << winner;
    cout << '\n';

    return 0;
}
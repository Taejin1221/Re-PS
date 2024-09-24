// Baekjoon12100.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

bool sumFlag[20];

void moveUp(vvi& board, int n) {
    for (int j = 0; j < n; j++) {
        fill(sumFlag, sumFlag + n, false);
        for (int i = 1; i < n; i++) {
            for (int k = i; k > 0; k--) {
                if (board[k - 1][j] == 0) {
                    board[k - 1][j] = board[k][j];
                    board[k][j] = 0;
                } else {
                    if (!sumFlag[k - 1] && board[k - 1][j] == board[k][j]) {
                        sumFlag[k - 1] = true;
                        board[k - 1][j] *= 2;
                        board[k][j] = 0;
                    }

                    break;
                }
            }
        }
    }
}

void moveDown(vvi& board, int n) {
    for (int j = 0; j < n; j++) {
        fill(sumFlag, sumFlag + n, false);
        for (int i = n - 2; i >= 0; i--) {
            for (int k = i; k < n - 1; k++) {
                if (board[k + 1][j] == 0) {
                    board[k + 1][j] = board[k][j];
                    board[k][j] = 0;
                } else {
                    if (!sumFlag[k + 1] && board[k + 1][j] == board[k][j]) {
                        sumFlag[k + 1] = true;
                        board[k + 1][j] *= 2;
                        board[k][j] = 0;
                    }

                    break;
                }
            }
        }
    }
}

void moveLeft(vvi& board, int n) {
    for (int i = 0; i < n; i++) {
        fill(sumFlag, sumFlag + n, false);
        for (int j = 1; j < n; j++) {
            for (int k = j; k > 0; k--) {
                if (board[i][k - 1] == 0) {
                    board[i][k - 1] = board[i][k];
                    board[i][k] = 0;
                } else {
                    if (!sumFlag[k - 1] && board[i][k - 1] == board[i][k]) {
                        sumFlag[k - 1] = true;
                        board[i][k - 1] *= 2;
                        board[i][k] = 0;
                    }

                    break;
                }
            }
        }
    }
}

void moveRight(vvi& board, int n) {
    for (int i = 0; i < n; i++) {
        fill(sumFlag, sumFlag + n, false);
        for (int j = n - 2; j >= 0; j--) {
            for (int k = j; k < n - 1; k++) {
                if (board[i][k + 1] == 0) {
                    board[i][k + 1] = board[i][k];
                    board[i][k] = 0;
                } else {
                    if (!sumFlag[k + 1] && board[i][k + 1] == board[i][k]) {
                        sumFlag[k + 1] = true;
                        board[i][k + 1] *= 2;
                        board[i][k] = 0;
                    }

                    break;
                }
            }
        }
    }
}

int getMax(vvi& board, int n) {
    int result = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result = max(result, board[i][j]);

    return result;
}

void print(vvi& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vvi origin(n, vi(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> origin[i][j];

    queue<pair<vvi, int>> q;
    q.push({ origin, 0 });

    int ans = 0;
    while (!q.empty()) {
        pair<vvi, int> curr = q.front(); q.pop();
        vvi currBoard = curr.first;

        ans = max(ans, getMax(currBoard, n));
        if (curr.second == 5)
            continue;

        vvi nextBoard = vvi(currBoard);
        moveUp(nextBoard, n);
        q.push({ nextBoard, curr.second + 1 });

        nextBoard = vvi(currBoard);
        moveDown(nextBoard, n);
        q.push({ nextBoard, curr.second + 1 });

        nextBoard = vvi(currBoard);
        moveLeft(nextBoard, n);
        q.push({ nextBoard, curr.second + 1 });

        nextBoard = vvi(currBoard);
        moveRight(nextBoard, n);
        q.push({ nextBoard, curr.second + 1 });
    }

    cout << ans << '\n';

    return 0;
}

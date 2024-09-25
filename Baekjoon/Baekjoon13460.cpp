// Baekjoon13460.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vvc = vector<vector<char>>;

struct Node {
    int type, time;
    pii red, blue;

    Node(int type, pii red, pii blue, int time): type(type), red(red), blue(blue), time(time) { }
};

int n, m;
int rows[4], cols[4];
char board[4][10][11];

// -1 : Fail, 0 : Not end, 1 : Success
int tiltLeft(int type, pii& red, pii& blue) {
    char leftColor, rightColor;
    pii leftPos, rightPos;
    if (red.second <= blue.second) {
        leftPos = red, rightPos = blue;
        leftColor = 'r', rightColor = 'b';
    } else {
        leftPos = blue, rightPos = red;
        leftColor = 'b', rightColor = 'r';
    }

    int result = 0;
    int next = leftPos.second - 1;
    while (board[type][leftPos.first][next] != '#') {
        if (board[type][leftPos.first][next] == 'O') {
            if (leftColor == 'b')
                return -1;
            else {
                leftPos = { -1, -1 };
                result = 1;
                break;
            }
        } else
            leftPos.second = next;
        next = leftPos.second - 1;
    }

    next = rightPos.second - 1;
    while (board[type][rightPos.first][next] != '#') {
        if (board[type][rightPos.first][next] == 'O') {
            if (rightColor == 'b')
                return -1;
            else
                return 1;
        } else {
            if (leftPos.first == rightPos.first && leftPos.second == next)
                break;
            rightPos.second = next;
        }
        next = rightPos.second - 1;
    }

    if (leftColor == 'r')
        red = leftPos, blue = rightPos;
    else
        red = rightPos, blue = leftPos;

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rows[0] = rows[2] = cols[1] = cols[3] = n;
    rows[1] = rows[3] = cols[0] = cols[2] = m;

    pii red, blue;
    for (int i = 0; i < n; i++) {
        cin >> board[0][i];
        for (int j = 0; j < m; j++) {
            if (board[0][i][j] == 'R') {
                board[0][i][j] = '.';
                red = { i, j };
            } else if (board[0][i][j] == 'B') {
                board[0][i][j] = '.';
                blue = { i, j };
            }
        }
    }

    for (int type = 1; type <= 3; type++) {
        for (int i = 0; i < rows[type - 1]; i++)
            for (int j = 0; j < cols[type - 1]; j++)
                board[type][cols[type - 1] - (j + 1)][i] = board[type - 1][i][j];
    }

    queue<Node> q;
    q.push(Node(0, red, blue, 0));

    int ans = -1;
    while (!q.empty()) {
        Node curr = q.front(); q.pop();

        if (curr.time == 10)
            continue;

        int prevType = curr.type;
        pii prevRed = curr.red, prevBlue = curr.blue;
        for (int i = 1; i <= 4; i++) {
            int nextType = (curr.type + i) % 4;
            pii nextRed = { cols[prevType] - (prevRed.second + 1), prevRed.first },
                nextBlue = { cols[prevType] - (prevBlue.second + 1), prevBlue.first };

            prevRed = nextRed, prevBlue = nextBlue;

            int result = tiltLeft(nextType, nextRed, nextBlue);
            if (result == 1) {
                ans = curr.time + 1;
                break;
            } else if (result == 0)
                q.push(Node(nextType, nextRed, nextBlue, curr.time + 1));

            prevType = nextType;
        }

        if (ans != -1)
            break;
    }

    cout << ans << '\n';

    return 0;
}

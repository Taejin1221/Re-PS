// Baekjoon17265.cpp
#include <iostream>

#include <string>

using namespace std;

using pii = pair<int, int>;

const int moves[2][2] = { { 1, 0 }, { 0, 1 } };

int n;
char map[5][5];
pii ans = { -0x3f3f3f3f, 0x3f3f3f3f };

int getValue(string expr) {
    int prev = expr[0] - '0';
    for (int i = 1; i < expr.size(); i += 2) {
        if (expr[i] == '+')
            prev += expr[i + 1] - '0';
        else if (expr[i] == '-')
            prev -= expr[i + 1] - '0';
        else
            prev *= expr[i + 1] - '0';
    }

    return prev;
}

void dfs(int row, int col, string expr) {
    if (row == (n - 1) && col == (n - 1)) {
        ans.first = max(ans.first, getValue(expr));
        ans.second = min(ans.second, getValue(expr));
    } else {
        for (int i = 0; i < 2; i++) {
            int nextRow = row + moves[i][0], nextCol = col + moves[i][1];
            if ((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < n)) {
                expr.push_back(map[nextRow][nextCol]);
                dfs(nextRow, nextCol, expr);
                expr.pop_back();
            }
        }
    }
}

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    string expr;
    expr.push_back(map[0][0]);
    dfs(0, 0, expr);

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}

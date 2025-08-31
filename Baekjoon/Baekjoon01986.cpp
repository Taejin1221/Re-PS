// Baekjoon01986.cpp
#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

const pii moves[3][8] = {
    { { 0, 0 }, },
    { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } },
    { { -2, 1 }, { -1, 2 }, { 1, 2 }, { 2, 1 }, { 2, -1 }, { 1, -2 }, { -1, -2 }, { -2, -1 } }
};


int n, m;
int board[1'000][1'000] = { { 0, }, }; // -1: can't go, 1: queen, 2: knight, 3: pawn

void solve(int type, pii& pos) {
    if (type == 1) {
        for (int i = 0; i < 8; i++) {
            int newRow = pos.first + moves[type][i].first, newCol = pos.second + moves[type][i].second;
            while (((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) && board[newRow][newCol] <= 0) {
                board[newRow][newCol] = -1;
                newRow += moves[type][i].first, newCol += moves[type][i].second;
            }
        }
    } else {
        for (int i = 0; i < 8; i++) {
            int newRow = pos.first + moves[type][i].first, newCol = pos.second + moves[type][i].second;
            if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m))
                board[newRow][newCol] = -1;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    vector<pii> objects[4];
    for (int type = 1; type <= 3; type++) {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
            int row, col;
            cin >> row >> col;

            objects[type].push_back({ --row, --col });

            board[row][col] = type;
        }
    }

    for (int i = 1; i <= 2; i++)
        for (pii& object : objects[i])
            solve(i, object);

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0)
                ans++;

    cout << ans << '\n';

    return 0;
}

// Baekjoon14500.cpp
#include <iostream>

#include <vector>

using namespace std;

const int tetromino[19][3][2] = {
    { { 0, 1 }, { 0, 2 }, { 0, 3 } }, // 1-1
    { { 1, 0 }, { 2, 0 }, { 3, 0 } }, // 1-2
    { { 0, 1 }, { 1, 0 }, { 1, 1 } }, // 2
    { { 1, 0 }, { 2, 0 }, { 2, 1 } }, // 3-1
    { { 0, 1 }, { -1, 1 }, { -2, 1 } }, // 3-2
    { { 0, 1 }, { 0, 2 }, { -1, 2 } }, // 3-3
    { { 1, 0 }, { 1, 1 }, { 1, 2 } }, // 3-4
    { { 0, 1 }, { 1, 1 }, { 2, 1 } }, // 3-5
    { { 0, 1 }, { 1, 0 }, { 2, 0 } }, // 3-6
    { { 1, 0 }, { 0, 1 }, { 0, 2} }, // 3-7
    { { 0, 1 }, { 0, 2 }, { 1, 2 } }, // 3-8
    { { 1, 0 }, { 1, 1 }, { 2, 1 } }, // 4-1
    { { 1, 0 }, { 0, 1 }, { -1, 1 } }, // 4-2
    { { 0, 1 }, { -1, 1 }, { -1, 2 } }, // 4-3
    { { 0, 1 }, { 1, 1 }, { 1, 2 } }, // 4-4
    { { 0, 1 }, { 0, 2 }, { 1, 1 } }, // 5-1
    { { 1, 0 }, { 2, 0 }, { 1, 1 } }, // 5-2
    { { 0, 1 }, { 0, 2 }, { -1, 1 } }, // 5-3
    { { 0, 1 }, { -1, 1 }, { 1, 1 } } // 5-4
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> paper(n, vector<int> (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m ; j++)
            cin >> paper[i][j];

    int ans = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            for (int i = 0; i < 19; i++) {
                int result = paper[row][col];
                for (int j = 0; j < 3; j++) {
                    int newRow = row + tetromino[i][j][0], newCol = col + tetromino[i][j][1];
                    if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m))
                        result += paper[newRow][newCol];
                }
                ans = max(ans, result);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
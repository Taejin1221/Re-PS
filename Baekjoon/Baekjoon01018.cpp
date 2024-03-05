// Baekjoon01018.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    string correctBoard[2] = { "WBWBWBWB", "BWBWBWBW" };

    string board[50];
    for (int i = 0; i < n; i++)
        cin >> board[i];

    int ans = 0x3f3f3f3f;
    for (int type = 0; type < 2; type++) {
        for (int row = 0; row <= n - 8; row++) {
            for (int col = 0; col <= m - 8; col++) {
                int incorrect = 0;
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++)
                        if (correctBoard[type][j] != board[row + i][col + j])
                            incorrect++;
                    type = (type + 1) % 2;
                }

                ans = min(ans, incorrect);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
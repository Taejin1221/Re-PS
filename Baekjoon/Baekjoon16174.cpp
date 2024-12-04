// Baekjoon16174.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int game[64][64];
    bool dp[64][64] = { { true, }, };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> game[i][j];

            if (dp[i][j]) {
                int nextRow = i + game[i][j], nextCol = j + game[i][j];
                if (0 <= nextRow && nextRow < n)
                    dp[nextRow][j] = true;

                if (0 <= nextCol && nextCol < n)
                    dp[i][nextCol] = true;
            }
        }
    }

    cout << (dp[n - 1][n - 1] ? "HaruHaru" : "Hing") << '\n';

    return 0;
}

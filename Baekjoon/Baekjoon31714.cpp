// Baekjoon31714.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, d;
    cin >> n >> m >> d;

    int seat[1'000][1'000];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> seat[i][j];
            seat[i][j] += (i + 1) * d;
        }
        sort(seat[i], seat[i] + m);
    }

    bool ans = true;
    for (int col = 0; col < m; col++) {
        for (int row = 0; row < n - 1; row++) {
            if (seat[row][col] >= seat[row + 1][col]) {
                ans = false;
                break;
            }
        }

        if (!ans)
            break;
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}

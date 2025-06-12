// Baekjoon01996.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    char map[1'000][1'001];

    int ans[1'000][1'001] = { { 0, }, };
    for (int i = 0; i < n; i++) {
        cin >> map[i];
        for (int j = 0; j < n; j++) {
            if (map[i][j] != '.') {
                ans[i][j] = -1;
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        int newRow = i + a, newCol = j + b;
                        if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < n) && (ans[newRow][newCol] != -1))
                            ans[newRow][newCol] += map[i][j] - '0';
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i][j] == -1)
                cout << '*';
            else if (ans[i][j] < 10)
                cout << ans[i][j];
            else
                cout << 'M';
        }
        cout << '\n';
    }

    return 0;
}

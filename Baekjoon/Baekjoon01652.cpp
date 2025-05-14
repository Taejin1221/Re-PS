// Baekjoon01652.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    char room[100][101];
    for (int i = 0; i < n; i++)
        cin >> room[i];

    int ans1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (room[i][j] == '.' && room[i][j + 1] == '.') {
                ans1++;
                while (j < n && room[i][j] == '.')
                    j++;
            }
        }
    }

    int ans2 = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (room[i][j] == '.' && room[i + 1][j] == '.') {
                ans2++;
                while (i < n && room[i][j] == '.')
                    i++;
            }
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';

    return 0;
}

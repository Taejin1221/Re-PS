// Baekjoon28217.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int a[10][10], b[10][10];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < (i + 1); j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < (i + 1); j++)
            cin >> b[i][j];

    int ans = 0x3f3f3f3f, newA[10][10];
    for (int t = 0; t < 3; t++) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (i + 1); j++) {
                newA[i][j] = a[n - 1 - j][i - j];
                temp += (newA[i][j] != b[i][j]);
            }
        }
        ans = min(ans, temp);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < (i + 1); j++)
                a[i][j] = newA[i][j];

        temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (i + 1); j++) {
                newA[i][j] = a[i][i - j];
                temp += (newA[i][j] != b[i][j]);
            }
        }

        ans = min(ans, temp);
    }

    cout << ans << '\n';

    return 0;
}

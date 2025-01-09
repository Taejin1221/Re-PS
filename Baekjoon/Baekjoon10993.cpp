// Baekjoon10993.cpp
#include <iostream>

#include <algorithm>

using namespace std;

char ans[1023][2050];
int width[11] = { 0, 1, }, height[11] = { 0, 1, };

void solve(int n, int startRow, int startCol) {
    if (n == 1) {
        ans[startRow][startCol] = '*';

        return;
    }

    for (int i = 0; i < width[n]; i++)
        ans[startRow][startCol + i] = '*';

    int direction = (n % 2 == 0) ? 1 : -1;
    for (int i = 1; i < height[n]; i++) {
        ans[startRow + (i * direction)][startCol + i] = '*';
        ans[startRow + (i * direction)][startCol + width[n] - i - 1] = '*';
    }

    int newRow = (startRow + startRow + (height[n] - 1) * direction) / 2;
    solve(n - 1, newRow, startCol + (height[n] + 1) / 2);
}

int main(void) {
    for (int i = 2; i <= 10; i++) {
        width[i] = width[i - 1] + (1 << i);
        height[i] = (1 << i) - 1;
    }

    int n;
    cin >> n;

    for (int i = 0; i < height[n]; i++)
        fill(ans[i], ans[i] + 2050, ' ');

    if (n % 2 == 0)
        solve(n, 0, 0);
    else
        solve(n, height[n] - 1, 0);

    for (int i = 0; i < height[n]; i++)
        for (int j = width[n]; ans[i][j] == ' '; j--)
            ans[i][j] = '\0';

    for (int i = 0; i < height[n]; i++)
        cout << ans[i] << '\n';

    return 0;
}

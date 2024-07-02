// Baekjoon22341.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    int points[10'000][2];
    for (int i = 0; i < c; i++)
        cin >> points[i][0] >> points[i][1];

    int row = n, col = n;
    for (int i = 0; i < c; i++) {
        int cutRow = points[i][0], cutCol = points[i][1];
        if (!(cutRow <= row && cutCol <= col))
            continue;

        int areaRow = col * cutRow, areaCol = row * cutCol;

        if (areaRow >= areaCol)
            row = cutRow;
        else
            col = cutCol;
    }

    cout << row * col << '\n';

    return 0;
}
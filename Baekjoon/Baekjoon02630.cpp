// Baekjoon02630.cpp
#include <iostream>

#include <vector>

#define ROW first
#define COL second

using namespace std;

using pii = pair<int, int>;

int ans[2];
vector<vector<int>> paper;

void cutPaper(pii start, int size) {
    int row = start.ROW, col = start.COL;

    bool isEnd = true;
    int color = paper[row][col];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (paper[row + i][col + j] != color) {
                isEnd = false;
                break;
            }
        }

        if (!isEnd)
            break;
    }

    if (isEnd) {
        ans[color]++;
    } else {
        int half = size / 2;

        cutPaper(start, half);
        cutPaper({ row, col + half }, half);
        cutPaper({ row + half, col }, half);
        cutPaper({ row + half, col + half }, half);
    }
}

int main(void) {
    int n;
    cin >> n;

    paper = vector<vector<int>> (n, vector<int> (n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> paper[i][j];

    cutPaper({ 0, 0 }, n);

    cout << ans[0] << '\n' << ans[1] << '\n';

    return 0;
}
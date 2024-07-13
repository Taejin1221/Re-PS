// Baekjoon02638.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m, outSideNum;
int paper[100][100];
bool visited[100][100], isOutside[100][100];

void checkOutside(int row, int col) {
    for (int i = 0; i < 4; i++) {
        int newRow = row + moves[i][0], newCol = col + moves[i][1];
        if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
            if (!visited[newRow][newCol] && paper[newRow][newCol] == 0) {
                visited[newRow][newCol] = true;
                if (!isOutside[newRow][newCol]) {
                    isOutside[newRow][newCol] = true;
                    outSideNum++;
                }
                checkOutside(newRow, newCol);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> paper[i][j];

    int ans = 0;
    vector<pii> melt;
    checkOutside(0, 0);
    for (ans = 0; outSideNum < n * m; ans++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (paper[i][j] == 1) {
                    int surround = 0;
                    for (int k = 0; k < 4; k++) {
                        int newRow = i + moves[k][0], newCol = j + moves[k][1];
                        if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m))
                            surround += isOutside[newRow][newCol];
                    }

                    if (surround >= 2)
                        melt.push_back({ i, j });
                }
            }
        }

        while (!melt.empty()) {
            pii curr = melt.back(); melt.pop_back();
            paper[curr.first][curr.second] = 0;
        }

        for (int i = 0; i < n; i++)
            fill(visited[i], visited[i] + m, false);
        checkOutside(0, 0);
    }

    cout << ans << '\n';

    return 0;
}
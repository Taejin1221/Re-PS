// Baekjoon01491.cpp
#include <iostream>

#define MAX 500

using namespace std;

using pii = pair<int, int>;

const int moves[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

int main(void) {
    int n, m;
    cin >> m >> n;

    pii ans = { 0, 0 };
    int dir = 0, visitNum = 1;
    bool visited[MAX][MAX] = { { true, }, };
    while (visitNum < n * m) {
        int nextRow = ans.first + moves[dir][0], nextCol = ans.second + moves[dir][1];
        if ((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < m) && (!visited[nextRow][nextCol])) {
            visited[nextRow][nextCol] = true;
            visitNum++;
            ans = { nextRow, nextCol };
        } else {
            dir = (dir + 1) % 4;
        }
    }

    cout << ans.second << ' ' << ans.first << '\n';

    return 0;
}

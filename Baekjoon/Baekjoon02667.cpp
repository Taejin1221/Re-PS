// Baekjoon02667.cpp
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> map;
vector<vector<bool>> visited;

int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int dfs(int row, int col) {
    int result = 1;
    for (int i = 0; i < 4; i++) {
        int nextRow = row + moves[i][0], nextCol = col + moves[i][1];
        if ((0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < n)) {
            if (map[nextRow][nextCol] == '1' && !visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = true;
                result += dfs(nextRow, nextCol);
            }
        }
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    map = vector<string> (n);
    visited = vector<vector<bool>> (n, vector<bool> (n));
    for (int i = 0; i < n; i++)
        cin >> map[i];


    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == '1' && !visited[i][j]) {
                visited[i][j] = true;

                ans.push_back(dfs(i, j));
            }
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int& a : ans)
        cout << a << '\n';

    return 0;
}
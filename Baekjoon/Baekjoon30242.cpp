// Baekjoon30242.cpp
#include <iostream>

#include <vector>

using namespace std;

int n;
bool visited[3][40]; // col, down, up
vector<int> ans;

bool solve(vector<int>& ans, int row) {
    if (row == n)
        return true;

    if (ans[row] != -1)
        return solve(ans, row + 1);

    for (int i = 0; i < n; i++) {
        int idx1 = row - i + (n - 1), idx2 = row + i;
        if (!visited[0][i] && !visited[1][idx1] && !visited[2][idx2]) {
            visited[0][i] = visited[1][idx1] = visited[2][idx2] = true;
            ans[row] = i;
            if (solve(ans, row + 1))
                return true;
            visited[0][i] = visited[1][idx1] = visited[2][idx2] = false;
            ans[row] = -1;
        }
    }

    return false;
}

int main(void) {
    cin >> n;

    ans = vector<int> (n);
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
        ans[i]--;
        if (ans[i] != -1)
            visited[0][ans[i]] = visited[1][i - ans[i] + (n - 1)] = visited[2][i + ans[i]] = true;
    }

    bool can = solve(ans, 0);
    if (can)
        for (int i = 0; i < n; i++)
            cout << ans[i] + 1 << ' ';
    else
        cout << -1;
    cout << '\n';

    return 0;
}

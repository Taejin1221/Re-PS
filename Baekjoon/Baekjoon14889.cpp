// Baekjoon14889.cpp
#include <iostream>

#define ABS(x) (((x) > 0) ? (x) : (-(x)))

using namespace std;

int n, ans = 0x3f3f3f3f;
int stats[20][20];
bool teamInfo[20];

void solve(int idx, int teamANum) {
    if (idx >= n)
        return;
    else if (teamANum == n / 2) {
        int resultA = 0, resultB = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (teamInfo[i] == teamInfo[j])
                    (teamInfo[i] ? resultA : resultB) += stats[i][j] + stats[j][i];

        ans = min(ans, ABS(resultA - resultB));
    } else {
        solve(idx + 1, teamANum);
        teamInfo[idx] = true;
        solve(idx + 1, teamANum + 1);
        teamInfo[idx] = false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> stats[i][j];

    solve(0, 0);

    cout << ans << '\n';

    return 0;
}
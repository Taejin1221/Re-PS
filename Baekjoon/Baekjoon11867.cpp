// Baekjoon11867.cpp
#include <iostream>

using namespace std;

int dp[101][101];

// 내가 지는 경우는 내가 무슨 짓을 해도 상대방이 이길 때
// 즉, 모든 분기가 다 true일 때
bool solve(int n, int m) {
    if (n == 1 && m == 1)
        return false;

    if (!dp[n][m]) {
        bool amIWin = false;

        for (int i = 1; i < n; i++)
            if (!solve(i, n - i))
                amIWin = true;

        for (int i = 1; i < m; i++)
            if (!solve(i, m - i))
                amIWin = true;

        dp[n][m] = amIWin ? 1 : -1;
    }

    return dp[n][m] == 1;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    if (solve(n, m))
        cout << "A";
    else
        cout << "B";
    cout << '\n';

    return 0;
}

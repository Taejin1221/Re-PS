// Baekjoon02225.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    int dp[201][201] = { { 0, }, }; // { 개수, 목표 }
    for (int i = 0; i <= n; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1'000'000'000;
            }
        }
    }

    cout << dp[m][n] << '\n';

    return 0;
}

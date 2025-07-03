#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int arr[15][15];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int dp[15][15] = { { 2, }, };
    for (int i = 1; i < n; i++)
        dp[0][i] = dp[i][0] = i + 2;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];


    cout << dp[n - 1][n - 1] << ' ' << n * n << '\n';

    return 0;
}

// Baekjoon11054.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[1'000], dp[2][1'000] = { { 0, }, };

    cin >> arr[0]; dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        for (int j = i - 1; j >= 0; j--)
            if (arr[j] < arr[i])
                dp[0][i] = max(dp[0][i], dp[0][j]);
        dp[0][i]++;
    }

    dp[1][n - 1] = 1;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[i])
                dp[1][i] = max(dp[1][i], dp[1][j]);
        dp[1][i]++;
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[0][i] + dp[1][i] - 1);

    cout << ans << '\n';

    return 0;
}
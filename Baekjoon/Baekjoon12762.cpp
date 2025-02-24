// Baekjoon12762.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int arr[1'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dp[2][1'000];
    for (int i = 0; i < n; i++)
        dp[0][i] = dp[1][i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = i - 1; j >= 0; j--)
            if (arr[j] > arr[i])
                dp[0][i] = max(dp[0][i], dp[0][j] + 1);

    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[i])
                dp[1][i] = max(dp[1][i], dp[1][j] + 1);

    int ans = 1;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[0][i] + dp[1][i] - 1);
    cout << ans << '\n';

    return 0;
}

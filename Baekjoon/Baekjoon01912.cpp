// Baekjoon01912.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dp(n);
    dp[0] = arr[0];

    int ans = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);

        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}
// Baekjoon11053.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[1'000], dp[1'000] = { 0, };
    cin >> arr[0]; dp[0] = 1;

    int ans = 1;
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i]++;
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}
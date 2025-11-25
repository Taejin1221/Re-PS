// Baekjoon11055.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[1'000], dp[1'000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    int ans = dp[0];
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);

        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}

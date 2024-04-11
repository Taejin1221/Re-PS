// Baekjoon02565.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());

    vector<int> dp(n);
    dp[0] = 1;

    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--)
            if (arr[j].second < arr[i].second)
                dp[i] = max(dp[i], dp[j]);
        dp[i]++;

        ans = max(ans, dp[i]);
    }

    cout << n - ans << '\n';

    return 0;
}
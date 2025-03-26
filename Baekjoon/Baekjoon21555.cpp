// Baekjoon21555.cpp
#include <iostream>

using namespace std;

using ll = long long;

ll min(ll a, ll b) {
    return a < b ? a : b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    ll a[200'000], b[200'000];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    ll dp[2][200'000];
    dp[0][0] = a[0];
    dp[1][0] = b[0];

    for (int i = 1; i < n; i++) {
        dp[0][i] = min(dp[0][i - 1], dp[1][i - 1] + k) + a[i];
        dp[1][i] = min(dp[1][i - 1], dp[0][i - 1] + k) + b[i];
    }

    cout << min(dp[0][n - 1], dp[1][n - 1]) << '\n';

    return 0;
}

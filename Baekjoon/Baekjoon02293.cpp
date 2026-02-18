// Baekjoon02293.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int coins[100];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int dp[10'001] = { 0, };
    for (int i = 0; i < n; i++) {
        if (coins[i] <= k)
            dp[coins[i]]++;

        for (int j = coins[i] + 1; j <= k; j++)
            dp[j] += dp[j - coins[i]];
    }

    cout << dp[k] << '\n';

    return 0;
}

// Baekjoon02294.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    int coins[100];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int dp[10'001] = { 0, };
    for (int i = 1; i <= k; i++) {
        if (dp[i] == 0)
            dp[i] = 0x3f3f3f3f;

        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    cout << (dp[k] == 0x3f3f3f3f ? -1 : dp[k]) << '\n';

    return 0;
}

#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int dp[51] = { 1, 1, };
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + 1) % 1'000'000'007;
    }

    cout << dp[n] << '\n';
    
    return 0;
}

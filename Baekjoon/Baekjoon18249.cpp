// Baekjoon18249.cpp
#include <iostream>

#define MOD 1'000'000'007LL

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll dp[191'230] = { 0, 1, 2, };
    for (int i = 3; i <= 191'229; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;
}

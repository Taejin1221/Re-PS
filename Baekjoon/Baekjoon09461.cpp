// Baekjoon09461.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ll dp[101] = { 0, 1, 1, 1, 2, 2, };
    for (int i = 6; i <= 100; i++)
        dp[i] = dp[i - 1] + dp[i - 5];

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;
}
// Baekjoon17626.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0x3f3f3f3f);

    for (int i = 1; i * i <= n; i++)
        dp[i * i] = 1;

    for (int i = 1; i <= n; i++) {
        if (dp[i] != 1) {
            for (int j = 1; j * j < i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
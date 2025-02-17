// Baekjoon17212.cpp
#include <iostream>

#include <iostream>

using namespace std;

int main(void) {
    const int face[4] = { 1, 2, 5, 7 };

    int n;
    cin >> n;

    int dp[100'001];
    fill(dp, dp + 100'001, 100'000);

    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 4; j++)
            if (i >= face[j])
                dp[i] = min(dp[i], dp[i - face[j]] + 1);

    cout << dp[n] << '\n';

    return 0;
}

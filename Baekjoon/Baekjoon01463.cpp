// Baekjoon01463.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int dp[1'000'001];

int solve(int n) {
    if (n == 1)
        return 0;
    else {
        if (dp[n] == -1) {
            int result = 1'000'001;
            if (n % 3 == 0)
                result = min(result, solve(n / 3));
            if (n % 2 == 0)
                result = min(result, solve(n / 2));
            result = min(result, solve(n - 1));

            dp[n] = result + 1;
        }

        return dp[n];
    }
}

int main(void) {
    int n;
    cin >> n;

    fill(dp, dp + n + 1, -1);

    cout << solve(n) << '\n';

    return 0;
}
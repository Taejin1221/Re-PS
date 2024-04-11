// Baekjoon24416.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

pii ans = { 0, 0 };
int dp[41];

int fib(int n) {
    if (n == 1 || n == 2) {
        ans.first++;
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main(void) {
    int n;
    cin >> n;

    fib(n);

    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        ans.second++;
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}
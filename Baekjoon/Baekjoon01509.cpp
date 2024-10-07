// Baekjoon01509.cpp
#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

int dp[2'500][2'500];
bool isPalindrome[2'500][2'500];

int solve(int start, int end) {
    if (isPalindrome[start][end])
        return 1;
    else {
        if (!dp[start][end]) {
            dp[start][end] = 0x3f3f3f3f;

            for (int i = start; i < end; i++) {
                if (isPalindrome[start][i]) {
                    dp[start][end] = min(dp[start][end], solve(i + 1, end) + 1);
                }
            }
        }

        return dp[start][end];
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    int n = str.size();
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (str[i] == str[j] && (i + 1 >= j - 1 || isPalindrome[i + 1][j - 1]))
                isPalindrome[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << isPalindrome[i][j] << ' ';
        cout << '\n';
    }

    cout << solve(0, n - 1) << '\n';

    return 0;
}
// Baekjoon31835.cpp
#include <iostream>

using namespace std;

int dp[2][2'000];
char expression[2'000];

int solve(int i, bool isTrue) {
    if (i == 0) {
        if ((isTrue && expression[i] == 'T') || (!isTrue && expression[i] == 'F'))
            return 0;
        else
            return 1;
    }

    if (dp[isTrue][i] == -1) {
        int frontT = solve(i - 2, true), frontF = solve(i - 2, false);

        int ans = 0x3f3f3f3f;        
        if (isTrue) { // To: (? | T, T | F, T & T)
            if (expression[i - 1] == '|') {
                if (expression[i] == 'T') // From: ? | T
                    ans = 0; // To: (? | T)
                else // From: ? | F
                    ans = min(1, frontT); // To: (? | T, T | F)
            } else { // To: (? | T, T | F, T & T)
                if (expression[i] == 'T') // From: ? & T
                    ans = min(1, frontT); // To: (? | T, T & T)
                else // From: ? & F
                    ans = min(2, frontT + 1); // To: (? | T, T | F, T & T)
            }
        } else { // To: (? & F, F & T, F | F)
            if (expression[i - 1] == '|') {
                if (expression[i] == 'T') // From: ? | T
                    ans = min(2, frontF + 1); // To: (? & F, F & T, F | F)
                else // From: ? | F
                    ans = min(1, frontF); // To: (? & F, F | F)
            } else {
                if (expression[i] == 'T') // From: ? & T
                    ans = min(1, frontF); // To: (? & F, F & T)
                else // From: ? & F
                    ans = 0; // To: (? & F)
            }
        }

        dp[isTrue][i] = ans;
    }

    return dp[isTrue][i];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> expression[i];
        dp[0][i] = dp[1][i] = -1;
    }

    char c;
    cin >> c;

    cout << solve(n - 1, (c == 'T')) << '\n';

    return 0;
}

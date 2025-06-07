#include <iostream>

using namespace std;

void solve(void) {
    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int dp[1'001][1'001] = { { 0, }, };
    dp[1][1] = dp[2][1] = dp[3][1] = 1;

    for (int i = 2; i <= 1'000; i++) {
        for (int j = 2; j <= 1'000; j++) {
            for (int k = 1; k <= 3; k++) {
                if (i - k >= 1)
                    dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % 1'000'000'009;
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        cout << dp[n][m] << '\n';
    }
    
    return 0;
}

// Baekjoon25343.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[100][100];
    int dp[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            dp[i][j] = 1;
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int ii = i; ii >= 0; ii--) {
                for (int jj = j; jj >= 0; jj--) {
                    if (ii == i && jj == j)
                        continue;

                    if (arr[ii][jj] < arr[i][j])
                        dp[i][j] = max(dp[i][j], dp[ii][jj] + 1);

                }
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << '\n';

    return 0;
}

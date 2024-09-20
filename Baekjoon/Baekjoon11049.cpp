// Baekjoon11049.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    pii mat[500] = { { 0, 0 }, };
    for (int i = 0; i < n; i++)
        cin >> mat[i].first >> mat[i].second;


    ll dp[500][500] = { { 0, }, };
    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = mat[i].first * mat[i].second * mat[i + 1].second;

    for (int dis = 2; dis < n; dis++) {
        for (int i = 0; i < n - dis; i++) {
            int j = i + dis;
            dp[i][j] = 0x3f3f3f3f3f3f3f3f;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j],
                    dp[i][k] + dp[k + 1][j] + (mat[i].first * mat[k].second * mat[j].second));
            }
        }
    }

    cout << dp[0][n - 1] << '\n';

    return 0;
}
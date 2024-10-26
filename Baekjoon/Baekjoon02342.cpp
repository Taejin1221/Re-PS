// Baekjoon02342.cpp
#include <iostream>

#include <algorithm>

#define MAX 100'001
#define INF 0x3f3f3f3f

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

int getCost(int source, int dest) {
    if (source == 0)
        return 2;
    else {
        int diff = ABS(source - dest);
        if (diff == 1 || diff == 3)
            return 3;
        else
            return 4;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 0, arr[MAX];
    fill(arr, arr + MAX, INF);
    while (arr[n] != 0) {
        n++;
        cin >> arr[n];
    }

    int dp[5][5][MAX];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            fill(dp[i][j], dp[i][j] + MAX, INF);
    dp[0][0][0] = 0;

    for (int k = 0; k < n - 1; k++) {
        int target = arr[k + 1];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if ((k != 0 && i == j) || dp[i][j][k] == INF)
                    continue;

                if (i != target && j != target) {
                    dp[target][j][k + 1] = min(dp[target][j][k + 1], dp[i][j][k] + getCost(i, target));

                    dp[i][target][k + 1] = min(dp[i][target][k + 1], dp[i][j][k] + getCost(j, target));
                } else if (i == target)
                    dp[target][j][k + 1] = min(dp[target][j][k + 1], dp[i][j][k] + 1);
                else if (j == target)
                    dp[i][target][k + 1] = min(dp[i][target][k + 1], dp[i][j][k] + 1);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            ans = min(ans, dp[i][j][n - 1]);

    cout << ans << '\n';

    return 0;
}
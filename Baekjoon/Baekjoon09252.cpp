// Baekjoon09252.cpp
#include <iostream>

#include <string>
#include <vector>

#define MAX 1'000

using namespace std;

using pos = pair<int, int>;
using pip = pair<int, pos>;

int main(void) {
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    pip dp[MAX][MAX] = { { { 0, { -1, -1 }, }, }, };
    if (a[0] == b[0])
        dp[0][0] = { 1, { -1, -1 } };

    for (int i = 1; i < n; i++) {
        if (a[i] == b[0]) {
            dp[i][0] = { 1, { -1, -1 } };
        } else
            dp[i][0] = { dp[i - 1][0].first, { i - 1, 0 } };
    }

    for (int i = 1; i < m; i++) {
        if (a[0] == b[i])
            dp[0][i] = { 1, { -1, -1 } };
        else
            dp[0][i] = { dp[0][i - 1].first, { 0, i - 1 } };
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i] == b[j])
                dp[i][j] = { dp[i - 1][j - 1].first + 1, { i - 1, j - 1 } };
            else {
                if (dp[i - 1][j].first < dp[i][j - 1].first) {
                    dp[i][j] = { dp[i][j - 1].first, { i, j - 1 } };
                } else {
                    dp[i][j] = { dp[i - 1][j].first, { i - 1, j } };
                }
            }
        }
    }

    cout << dp[n - 1][m - 1].first << '\n';
    if (dp[n - 1][m - 1].first != 0) {
        vector<char> rLCS;
        pos idx = { n - 1, m - 1 };
        while (!(idx.first == -1 && idx.second == -1)) {
            if (a[idx.first] == b[idx.second])
                rLCS.push_back(a[idx.first]);
            idx = dp[idx.first][idx.second].second;
        }

        for (auto iter = rLCS.rbegin(); iter != rLCS.rend(); ++iter)
            cout << *iter;
        cout << '\n';
    }

    return 0;
}
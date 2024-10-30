// Baekjoon32187.cpp
#include <iostream>

#include <vector>

using namespace std;

using ll = long long;

using pii = pair<int, ll>;

ll dp[2][100'000];

ll getMaximum(vector<pii>& stck) {
    dp[0][0] = 0;
    dp[1][0] = stck[0].second;
    for (int i = 1; i < stck.size(); i++) {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
        dp[1][i] = dp[0][i - 1] + stck[i].second;
    }

    return max(dp[0][stck.size() - 1], dp[1][stck.size() - 1]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; // n: 음식 수, m: 학생 
    cin >> n >> m;

    ll ans = 0LL;
    vector<pii> stck[100'001]; // { student, happy }
    for (int i = 1; i <= m; i++) {
        int l;
        cin >> l;

        for (int j = 0; j < l; j++) {
            int food; ll happy;
            cin >> food >> happy;

            if (stck[food].empty())
                stck[food].push_back({ i, happy });
            else {
                if (stck[food].back().first + 1 != i) {
                    ans += getMaximum(stck[food]);
                    while (!stck[food].empty())
                        stck[food].pop_back();
                }
                stck[food].push_back({ i, happy });
            }
        }
    }

    for (int i = 1; i <= n; i++)
        if (!stck[i].empty())
            ans += getMaximum(stck[i]);

    cout << ans << '\n';

    return 0;
}
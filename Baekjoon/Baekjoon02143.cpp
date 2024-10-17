// Baekjoon02143.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll target;
    cin >> target;

    int n;
    cin >> n;

    ll prefixA[1'001] = { 0, };
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;

        prefixA[i + 1] = prefixA[i] + a;
    }

    vector<ll> AList;
    for (int len = 0; len < n; len++)
        for (int start = 0; start + len < n; start++)
            AList.push_back(prefixA[start + len + 1] - prefixA[start]);
    sort(AList.begin(), AList.end());

    int m;
    cin >> m;

    int prefixB[1'001] = { 0, };
    for (int i = 0; i < m; i++) {
        ll b;
        cin >> b;

        prefixB[i + 1] = prefixB[i] + b;
    }

    ll ans = 0;
    for (int len = 0; len < m; len++) {
        for (int start = 0; start + len < m; start++) {
            ll curr = prefixB[start + len + 1] - prefixB[start];
            ans += upper_bound(AList.begin(), AList.end(), target - curr) - lower_bound(AList.begin(), AList.end(), target - curr);
        }
    }

    cout << ans << '\n';

    return 0;
}
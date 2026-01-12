// Baekjoon28081.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll w, h, k;
    cin >> w >> h >> k;

    int n;
    cin >> n;

    ll prev = 0LL;
    vector<ll> ys;
    for (int i = 0; i < n; i++) {
        ll curr;
        cin >> curr;

        ys.push_back(curr - prev);
        prev = curr;
    }
    ys.push_back(h - prev);

    sort(ys.begin(), ys.end());

    int m;
    cin >> m;

    prev = 0LL;
    vector<ll> xs;
    for (int i = 0; i < m; i++) {
        int curr;
        cin >> curr;

        xs.push_back(curr - prev);
        prev = curr;
    }
    xs.push_back(w - prev);

    ll ans = 0LL;
    for (int i = 0; i < xs.size(); i++) {
        ll target = k / xs[i];

        ll idx = upper_bound(ys.begin(), ys.end(), target) - ys.begin();
        ans += idx;
    }

    cout << ans << '\n';

    return 0;
}

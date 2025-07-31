// Baekjoon32396.cpp
#include <iostream>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    ll prev, len = 1LL;
    cin >> prev;

    int ans = 0;
    for (ll i = 1LL; i < n; i++) {
        ll curr;
        cin >> curr;

        if (ABS(prev - curr) >= m) {
            ans += len / 2LL;
            len = 0;
        }

        prev = curr;
        len++;
    }

    ans += len / 2LL;

    cout << ans << '\n';

    return 0;
}

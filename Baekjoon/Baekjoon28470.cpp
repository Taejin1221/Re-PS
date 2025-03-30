// Baekjoon28470.cpp
#include <iostream>

#include <cmath>

using namespace std;

using ll = long long;

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll a[100'000];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll b[100'000];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    ll k[100'000];
    for (int i = 0; i < n; i++) {
        double temp;
        cin >> temp;
        
        k[i] = ll(temp * 10);
    }

    ll ans = 0LL;
    for (int i = 0; i < n; i++) {
        ll attackFirst = (a[i] * k[i]) / 10LL - b[i];
        ll defenceFirst = a[i] - (b[i] * k[i]) / 10LL;

        ans += max(attackFirst, defenceFirst);
    }

    cout << ans << '\n';

    return 0;
}

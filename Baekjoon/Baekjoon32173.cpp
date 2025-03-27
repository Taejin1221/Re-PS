// Baekjoon32173.cpp
#include <iostream>

using namespace std;

using ll = long long;

ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll ans;
    cin >> ans;

    ll sum = ans;
    for (int i = 1; i < n; i++) {
        ll curr;
        cin >> curr;

        ans = max(ans, curr - sum);
        sum += curr;
    }

    cout << ans << '\n';

    return 0;
}

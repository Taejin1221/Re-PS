#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ll n;
    cin >> n;

    ll ans = 0;
    for (ll i = 1LL; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n)
                ans += 1;
            else
                ans += 2;
        }
    }

    cout << ans << '\n';

    return 0;
}

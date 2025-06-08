// Baekjoon17427.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ll n;
    cin >> n;

    ll ans = 0LL;
    for (ll i = 1LL; i <= n; i++)
        ans += i * (n / i);

    cout << ans << '\n';

    return 0;
}

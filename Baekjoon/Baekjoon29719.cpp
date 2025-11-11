#include <iostream>

#define MOD 1'000'000'007

using namespace std;

using ll = long long;

ll myPow(ll base, ll exp) {
    ll result = 1LL;
    for (int i = 0; i < exp; i++)
        result = result * base % MOD;

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    ll a = myPow(m, n), b = myPow(m - 1, n);
    cout << ((a - b + MOD) % MOD) << '\n';

    return 0;
}

// Baekjoon15710.cpp
#include <iostream>
using namespace std;

using ll = long long;

const ll MOD = 1'000'000'007LL;

ll myPow(ll base, ll exp) {
    if (exp == 0)
        return 1LL;

    ll half = myPow(base, exp / 2);
    ll result = half * half % MOD;
    if (exp % 2 == 1)
        result = result * base % MOD;

    return result;
}

int main(void) {
    ll a, b, n;
    cin >> a >> b >> n;

    cout << myPow(2, 31 * (n - 1)) << '\n';

    return 0;
}
// Baekjoon13172.cpp
#include <iostream>

#define MOD 1'000'000'007

using namespace std;

using ll = long long;

ll myPow(ll base, ll exp) {
    if (exp == 0)
        return 1;
    else {
        ll half = myPow(base, exp / 2);
        ll result = half * half % MOD;
        if (exp % 2 == 1)
            result = result * base % MOD;
        
        return result;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    ll sum = 0LL;
    for (int i = 0; i < m; i++) {
        ll n, s;
        cin >> n >> s;

        // cout << myPow(n, s) << endl;

        ll inverse = myPow(n, MOD - 2);
        sum = (sum + (inverse * s) % MOD) % MOD;
    }

    cout << sum << '\n';

    return 0;
}
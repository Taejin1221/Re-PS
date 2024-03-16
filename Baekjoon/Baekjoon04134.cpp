// Baekjoon04134.cpp
#include <iostream>

using namespace std;

using ll = long long;

bool isPrime(ll n) {
    if (n <= 1)
        return false;
    else {
        for (ll i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;

        return true;
    }
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll ans;
        for (ans = n; !isPrime(ans); ans++);

        cout << ans << '\n';
    }

    return 0;
}
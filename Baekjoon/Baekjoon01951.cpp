// Baekjoon01951.cpp
#include <iostream>

#define MOD 1'234'567

using namespace std;

using ll = long long;

/*
1 ~ 9 : 1
10 ~ 99 : 2
100 ~ 999 : 3
1000 ~ 9999 : 4

102 100 ~ 102: 3 * 3
    99 ~ 10: 90 * 2
    9 ~ 1: 9 * 1
*/

int main(void) {
    int n;
    cin >> n;

    ll ans = 0LL;
    ll i, curr = 1LL, next = 10LL;
    for (i = 1; n >= next; i++) {
        ans = (ans + ((next - 1) - curr + 1) * i) % MOD;
        curr = next;
        next *= 10LL;
    }
    // next 처리
    ans = (ans + (n - curr + 1) * i) % MOD;

    cout << ans << '\n';

    return 0;
}
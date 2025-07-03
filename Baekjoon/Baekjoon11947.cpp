// Baekjoon11947.cpp
#include <iostream>

using namespace std;

using ll = long long;

ll getReverse(ll a) {
    int digit = 0;
    ll temp = 0LL;
    while (a) {
        temp *= 10;
        temp += 9 - (a % 10);
        a /= 10;
        digit++;
    }

    ll result = 0LL;
    while (digit) {
        result *= 10;
        result += temp % 10;
        temp /= 10;
        digit--;
    }

    return result;
}

void solve() {
    int n;
    cin >> n;

    if (n == 1'000'000'000)
        cout << n * getReverse(n);
    else {
        ll left = 100'000'000, right = 999'999'999;
        while (!(left <= n && n <= right)) {
            left /= 10;
            right /= 10;
        }

        ll half = right / 2;
        if (n < half)
            cout << n * getReverse(n);
        else
            cout << half * getReverse(half);
    }
    cout << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

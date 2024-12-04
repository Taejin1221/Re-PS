// Baekjoon29717.cpp
#include <iostream>

using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;

    ll exp = n * (n + 1) / 2;

    int left = 1, right = 1'000'000'000;
    while (left + 1 < right) {
        ll mid = (left + right) / 2;

        if (mid * (mid - 1) <= exp)
            left = mid;
        else
            right = mid;
    }

    cout << left << '\n';
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

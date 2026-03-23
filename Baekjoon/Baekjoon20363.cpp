#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;

    if (m > n) {
        ll temp = n;
        n = m;
        m = temp;
    }

    cout << (n + (m / 10) + m) << '\n';

    return 0;
}

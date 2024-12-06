// Baekjoon10093.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    ll a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << '\n';

        return 0;
    }

    if (a > b) {
        ll temp = a;
        a = b;
        b = temp;
    }

    cout << b - a - 1 << '\n';
    for (ll i = a + 1; i < b; i++)
        cout << i << ' ';
    cout << '\n';

    return 0;
}

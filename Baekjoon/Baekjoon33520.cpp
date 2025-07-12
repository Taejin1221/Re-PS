#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    ll w = 0, h = 0;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        w = max(w, min(a, b));
        h = max(h, max(a, b));
    }

    cout << (w * h) << '\n';

    return 0;
}

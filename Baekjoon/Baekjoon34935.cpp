#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    bool ans = true;

    ll prev;
    cin >> prev;
    for (int i = 1; i < n; i++) {
        ll curr;
        cin >> curr;

        if (prev >= curr)
            ans = false;
        prev = curr;
    }

    cout << (ans ? 1 : 0) << '\n';

    return 0;
}

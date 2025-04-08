#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        int comp = i;

        while (n % comp == 0) {
            ans++;
            comp *= i;
        }
    }

    cout << ans << '\n';
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

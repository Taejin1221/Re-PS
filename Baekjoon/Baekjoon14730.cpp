#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int c, k;
        cin >> c >> k;

        ans += c * k;
    }

    cout << ans << '\n';

    return 0;
}

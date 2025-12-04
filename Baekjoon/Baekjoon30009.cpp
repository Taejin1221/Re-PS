#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x, y, r;
    cin >> n >> x >> y >> r;

    pii ans = { 0, 0 };
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if (x - r == t || t == x + r)
            ans.second++;

        if (x - r < t && t < x + r)
            ans.first++;
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}

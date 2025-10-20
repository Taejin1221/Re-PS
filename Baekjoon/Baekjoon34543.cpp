#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, w;
    cin >> n >> w;

    int ans = n * 10;
    if (n >= 3)
        ans += 20;

    if (n >= 5)
        ans += 50;

    if (w > 1000)
        ans = max(0, ans - 15);

    cout << ans << '\n';

    return 0;
}

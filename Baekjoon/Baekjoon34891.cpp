#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int ans = n / m + (n % m != 0);
    cout << ans << '\n';

    return 0;
}

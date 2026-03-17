#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int rest = 1000 - n;

    int coin[6] = { 500, 100, 50, 10, 5, 1 };
    int ans = 0;
    for (int i = 0; i < 6; i++) {
        ans += rest / coin[i];
        rest %= coin[i];
    }

    cout << ans << '\n';

    return 0;
}

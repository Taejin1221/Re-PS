#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pii ans = { 0, 0 };
    for (int i = 1; i <= 5; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int sum = a + b + c + d;
        if (sum > ans.second)
            ans = { i, sum };
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}

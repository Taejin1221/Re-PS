#include <iostream>

using namespace std;

int main() {
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;

    int day1 = (a % c ? a / c + 1 : a / c);

    int ans = l - max(a / c + (a % c != 0), b / d + (b % d != 0));
    cout << ans << '\n';

    return 0;
}

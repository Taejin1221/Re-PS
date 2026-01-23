#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = (a + d) - (b + c);
    cout << (ans < 0 ? -ans : ans) << '\n';

    return 0;
}

// Baekjoon33166.cpp
#include <iostream>

using namespace std;

int main(void) {
    int p, q;
    cin >> p >> q;

    int a, b;
    cin >> a >> b;

    int ans = min(p, q) * a;
    ans += max(q - p, 0) * b;

    cout << ans << '\n';

    return 0;
}

// Baekjoon27110.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    int ans = min(a, n) + min(b, n) + min(c, n);
    cout << ans << '\n';

    return 0;
}

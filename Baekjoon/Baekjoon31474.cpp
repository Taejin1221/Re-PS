// Baekjoon31474.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    int n;
    cin >> n;

    ll ans = 1LL;
    for (int i = 1; i <= n; i += 2)
        ans *= n - i;

    cout << ans << '\n';

    return 0;
}
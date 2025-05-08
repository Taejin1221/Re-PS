// Baekjoon05692.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int fac[6] = { 0, 1, 2, 6, 24, 120 };

    int n;
    cin >> n;
    while (n) {
        int ans = 0;
        for (int i = 1; n; i++) {
            ans += fac[i] * (n % 10);
            n /= 10;
        }
        cout << ans << '\n';

        cin >> n;
    }

    return 0;
}

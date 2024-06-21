// Baekjoon06504.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int fib[30] = { 0, 1, 2, };
    for (int i = 3; i < 30; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;

        bool bx[30] = { false, };
        for (int i = 1; i < 30; i++) {
            if (num >= fib[30 - i]) {
                bx[i] = true;
                num -= fib[30 - i];
            }
        }

        int ans = 0;
        for (int i = 1; i < 30; i++) {
            ans += fib[30 - i - 1] * bx[i];
        }
        cout << ans << '\n';
    }

    return 0;
}
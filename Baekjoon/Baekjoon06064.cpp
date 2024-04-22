// Baekjoon06064.cpp
#include <iostream>

using namespace std;

int getGCD(int a, int b) {
    return (a % b) ? getGCD(b, a % b) : b;
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int lcm = (m * n) / getGCD(max(m, n), min(m, n));

        int ans = x;
        while (ans <= lcm && !(((ans % m) == (x % m)) && ((ans % n) == (y % n))))
                ans += m;

        cout << (ans <= lcm ? ans : -1) << '\n';
    }

    return 0;
}
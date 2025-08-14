// Baekjoon13412.cpp
#include <iostream>

using namespace std;

int getGCD(int a, int b) {
    return (b ? getGCD(b, a % b) : a);
}

void solve() {
    int n;
    cin >> n;

    int result = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int a = i, b = n / i;
            int gcd = getGCD(b, i);

            if (a * b / gcd == n)
                result++;
        }
    }

    cout << result << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
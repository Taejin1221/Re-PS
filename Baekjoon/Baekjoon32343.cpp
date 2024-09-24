// Baekjoon32343.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, a, b;
    cin >> n >> a >> b;

    int ans = (1 << n) - 1;
    if (a + b <= n) {
        for (int i = 0; i < n - (a + b); i++)
            ans -= (1 << i);
    } else {
        for (int i = 0; i < (a + b) - n; i++)
            ans -= (1 << i);
    }

    cout << ans << '\n';

    return 0;
}
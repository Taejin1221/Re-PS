// Baekjoon03360.cpp
#include <iostream>

#define MAX 100'000'001

#define MOD 1'000'000

using namespace std;

int main(void) {
    int n;
    cin >> n;

    n %= 6000000;

    int d_2 = 0, d_1 = 1, d, f_1 = 2, f;
    for (int i = 3; i <= n; i++) {
        d = (d_2 + (i % 3 == 0 ? 1 : 0)) % MOD;
        f = (f_1 + d) % MOD;

        d_2 = d_1;
        d_1 = d;
        f_1 = f;
    }

    cout << f << '\n';

    return 0;
}

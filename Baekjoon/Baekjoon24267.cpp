// Baekjoon24267.cpp
#include <iostream>

using namespace std;

#define sum(x) ((x) * ((x) + 1) / 2)
#define sum2(x) ((x) * ((x) + 1) * (2 * (x) + 1) / 6)

using ll = long long;

int main(void) {
    ll n;
    cin >> n;

    cout << (sum2(n - 2) + sum(n - 2)) / 2 << '\n' << 3 << '\n';

    return 0;
}
// Baekjoon12779.cpp
#include <iostream>

using namespace std;

using ll = long long;

ll getSquareNum(ll x) {
    ll left = 0, right = (2LL << 31);

    while (left + 1 < right) {
        ll mid = (left + right) / 2;

        if (mid * mid <= x)
            left = mid;
        else
            right = mid;
    }

    return left;
}

ll getGCD(ll x, ll y) {
    return (x % y == 0) ? y : getGCD(y, x % y);
}

int main(void) {
    ll a, b;
    cin >> a >> b;

    ll aN = getSquareNum(a), bN = getSquareNum(b);

    ll down = b - a, up = bN - aN;
    if (up == 0)
        cout << 0;
    else {
        ll gcd = getGCD(down, up);

        cout << (up / gcd) << '/' << (down / gcd);
    }
    cout <<'\n';

    return 0;
}

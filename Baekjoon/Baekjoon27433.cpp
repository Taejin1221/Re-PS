// Baekjoon27433.cpp
#include <iostream>

using namespace std;

using ll = long long;

ll fac(ll a) {
    return (a ? a * fac(a - 1) : 1);
}

int main(void) {
    ll n;
    cin >> n;

    cout << fac(n) << '\n';

    return 0;
}
// Baekjoon13241.cpp
#include <iostream>

using namespace std;

using ll = long long;

ll getGCD(ll a, ll b) {
    return (a % b) ? getGCD(b, a % b) : b;
}

int main(void) {
    ll a, b;
    cin >> a >> b;

    ll gcd = a > b ? getGCD(a, b) : getGCD(b, a);

    cout << a * b / gcd << '\n';

    return 0;
}
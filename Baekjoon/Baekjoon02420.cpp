// Baekjoon02420.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ll n, m;
    cin >> n >> m;

    ll ans = n - m;
    cout << (ans < 0 ? -ans : ans) << '\n';

    return 0;
}
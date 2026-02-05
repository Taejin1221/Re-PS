// Baekjoon33703.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    cout << (n * (n + 1) / 2LL) << '\n';

    return 0;
}

// Baekjoon25179.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ll n ,m;
    cin >> n >> m;

    cout << (((n - 1) % (m + 1) == 0) ? "Can\'t win" : "Can win") << '\n';

    return 0;
}

// Baekjoon01629.cpp
#include <iostream>

using namespace std;

using ll = long long;

ll c;

ll myPow(ll a, ll b) {
    if (b == 1)
        return a;
    else {
        ll half = myPow(a, b / 2);
        
        return ((half * half % c) * ((b % 2 == 1 ? a : 1) % c)) % c;
    }
}

int main(void) {
    ll a, b;
    cin >> a >> b >> c;

    cout << myPow(a, b) % c << '\n';

    return 0;
}
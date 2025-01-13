// Baekjoon10915.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ll n;
    cin >> n;

    if (n % 2 == 0)
        cout << (n - 1);
    else
        cout << (n / 2);
    cout << '\n';

    return 0;
}

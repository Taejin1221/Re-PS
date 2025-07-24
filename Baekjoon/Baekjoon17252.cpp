// Baekjoon17252.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ll n;
    cin >> n;

    bool ans = (n == 0 ? false : true);
    while (n) {
        if (n % 3LL == 2LL) {
            ans = false;
            break;
        }

        n /= 3LL;
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}

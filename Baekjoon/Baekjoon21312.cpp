#include <iostream>

using namespace std;

int main(void) {
    int ans = 1, odd = 0;
    int a, b, c;
    cin >> a >> b >> c;

    if (a % 2) {
        odd++;
        ans *= a;
    }

    if (b % 2) {
        odd++;
        ans *= b;
    }

    if (c % 2) {
        odd++;
        ans *= c;
    }

    if (odd)
        cout << ans;
    else
        cout << a * b * c;
    cout << '\n';

    return 0;
}

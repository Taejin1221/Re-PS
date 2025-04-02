#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int ans = 1;
    int newNum = n % 10 * 10 + (n / 10 + n % 10) % 10;
    while (newNum != n) {
        newNum = newNum % 10 * 10 + (newNum / 10 + newNum % 10) % 10;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}

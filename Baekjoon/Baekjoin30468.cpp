#include <iostream>

using namespace std;

int main(void) {
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;

    int sum = a + b + c + d;

    int ans = 0;
    if (sum < n * 4)
        ans = n * 4 - sum;
    cout << ans << '\n';

    return 0;
}
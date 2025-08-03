#include <iostream>

using namespace std;

bool isSurprise(int num) {
    int digit = 0, result = num;
    while (result) {
        digit += result % 10;
        result /= 10;
    }

    return (num % digit == 0);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (isSurprise(i) ? 1 : 0);
    cout << ans << '\n';

    return 0;
}

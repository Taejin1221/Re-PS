#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < 100'000; i++) {
        if (2 * i > n)
            continue;

        int temp = n - (2 * i);
        if (temp % 5 == 0)
            ans = min(ans, i + temp / 5);
    }

    cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';

    return 0;
}

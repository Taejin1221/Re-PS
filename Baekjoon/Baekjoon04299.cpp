#include <iostream>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

using pii = pair<int, int>;

int main() {
    int sum, diff;
    cin >> sum >> diff;

    pii ans = { -1, -1 };
    for (int i = 0; i <= 1'000; i++) {
        for (int j = 0; j <= 1'000; j++) {
            if (i + j == sum && ABS(i - j) == diff) {
                ans = {max(i, j), min(i, j)};
                break;
            }
        }

        if (ans.first != -1)
            break;
    }

    if (ans.first == -1)
        cout << ans.first;
    else
        cout << ans.first << ' ' << ans.second;
    cout << '\n';

    return 0;
}

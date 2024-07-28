// Baekjoon27496.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    int alcohol[1'000'000];
    for (int i = 0; i < n; i++)
        cin >> alcohol[i];

    int left = 0, ans = 0, drink = 0;
    for (int i = 0; i < n; i++) {
        drink += alcohol[i];

        if (i >= l)
            drink -= alcohol[left++];

        if (129 <= drink && drink <= 138)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
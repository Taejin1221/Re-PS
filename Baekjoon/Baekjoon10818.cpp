// Baekjoon10818.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ans1, ans2;
    cin >> ans1;
    ans2 = ans1;

    for (int i = 1; i < n; i++) {
        int temp;
        cin >> temp;

        ans1 = max(ans1, temp);
        ans2 = min(ans2, temp);
    }

    cout << ans2 << ' ' << ans1 << '\n';

    return 0;
}
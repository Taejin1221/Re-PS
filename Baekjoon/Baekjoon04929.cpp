// Baekjoon04929.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (n == 0)
        return false;

    int arr1[10'000], prefix1[10'001] = { 0, };
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        prefix1[i + 1] = prefix1[i] + arr1[i];
    }

    int m;
    cin >> m;

    int arr2[10'000], prefix2[10'001] = { 0, };

    int prev1, prev2;
    prev1 = -1;
    prev2 = -1;

    int ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
        prefix2[i + 1] = prefix2[i] + arr2[i];

        int simIdx = lower_bound(arr1, arr1 + n, arr2[i]) - arr1;
        if (simIdx < n && arr1[simIdx] == arr2[i]) {
            int seg1 = prefix1[simIdx + 1] - prefix1[prev1 + 1];
            int seg2 = prefix2[i + 1] - prefix2[prev2 + 1];

            ans += max(seg1, seg2);

            prev1 = simIdx;
            prev2 = i;
        }
    }

    int seg1 = prefix1[n] - prefix1[prev1 + 1];
    int seg2 = prefix2[m] - prefix2[prev2 + 1];

    ans += max(seg1, seg2);

    cout << ans << '\n';

    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (solve());

    return 0;
}

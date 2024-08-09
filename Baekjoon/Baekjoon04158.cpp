// Baekjoon04158.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, 상근[1'000'000], 선영[1'000'000];
    cin >> n >> m;
    while (!(n == 0 && m == 0)) {
        for (int i = 0; i < n; i++)
            cin >> 상근[i];

        for (int i = 0; i < n; i++)
            cin >> 선영[i];

        int ans = 0, leftIdx = 0, rightIdx = 0;
        while (leftIdx < n && rightIdx < m) {
            if (상근[leftIdx] == 선영[rightIdx]) {
                leftIdx++, rightIdx++;
                ans++;
            } else if (상근[leftIdx] > 선영[rightIdx])
                rightIdx++;
            else
                leftIdx++;
        }

        cout << ans << '\n';

        cin >> n >> m;
    }

    return 0;
}
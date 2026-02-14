// Baekjoon01027.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    int n;
    cin >> n;

    ll height[50];
    for (int i = 0; i < n; i++)
        cin >> height[i];

    int ans = 0;
    int cnt[50] = { 0, };
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool see = true;
            for (int k = i + 1; k < j; k++) {
                ll xDiff = j - i;
                if ((height[j] - height[i]) * (k - i) + height[i] * xDiff <= height[k] * xDiff)
                    see = false;
            }

            if (see)
                cnt[i]++, cnt[j]++;
        }

        ans = max(ans, cnt[i]);
    }

    cout << ans << '\n';

    return 0;
}

// Baekjoon01059.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int l;
    cin >> l;

    int s[1'000];
    for (int i = 0; i < l; i++)
        cin >> s[i];
    sort(s, s + l);

    int n;
    cin >> n;

    int prev = 0, ans = 0;
    for (int i = 0; i < l && prev <= n; i++) {
        if (prev < n && n < s[i]) {
            int a = prev + 1, b = s[i] - 1;
            ans = (n - a + 1) * (b - n + 1) - 1;
        }

        prev = s[i];
    }

    cout << ans << '\n';

    return 0;
}
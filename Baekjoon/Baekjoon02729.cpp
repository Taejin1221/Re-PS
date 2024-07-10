// Baekjoon02729.cpp
#include <iostream>

#include <string>

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    int ans[100] = { 0, };
    int carry = 0, idx = 0, aIdx, bIdx;
    for (aIdx = n - 1, bIdx = m - 1; aIdx >= 0 && bIdx >= 0; aIdx--, bIdx--) {
        ans[idx] = (a[aIdx] - '0')+ (b[bIdx] - '0') + carry;

        carry = ans[idx] / 2;
        ans[idx++] %= 2;
    }

    while (aIdx >= 0) {
        ans[idx] = (a[aIdx--] - '0') + carry;

        carry = ans[idx] / 2;
        ans[idx++] %= 2;
    }

    while (bIdx >= 0) {
        ans[idx] = (b[bIdx--] - '0') + carry;

        carry = ans[idx] / 2;
        ans[idx++] %= 2;
    }

    if (carry == 1)
        ans[idx++] = carry;

    idx--;
    while (idx > 0 && ans[idx] == 0)
        idx--;

    for (int i = idx; i >= 0; i--)
        cout << ans[i];
    cout << '\n';
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
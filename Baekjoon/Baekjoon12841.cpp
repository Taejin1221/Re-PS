// Baekjoon12841.cpp
#include <iostream>

using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll cross[100'000];
    for (int i = 0; i < n; i++)
        cin >> cross[i];

    ll left[100'000] = { 0, };
    for (int i = 1; i < n; i++) {
        ll curr;
        cin >> curr;

        left[i] = left[i - 1] + curr;
    }

    ll right[100'000] = { 0, };
    for (int i = 1; i < n; i++) {
        ll curr;
        cin >> curr;

        right[i] = right[i - 1] + curr;
    }

    pii ans = { 0, 0x3f3f3f3f3f3f3f3f };
    for (int i = 0; i < n; i++) {
        ll curr = cross[i];
        curr += left[i];
        curr += right[n - 1] - right[i];

        if (ans.second > curr) {
            ans = { i + 1, curr };
        }
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}

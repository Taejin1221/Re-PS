// Baekjoon12847.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int left = 0;
    ll ans = 0LL, curr = 0LL, arr[100'000];
    for (int right = 0; right < n; right++) {
        cin >> arr[right];

        curr += arr[right];
        if (right - left + 1 > m)
            curr -= arr[left++];

        ans = max(ans, curr);
    }

    cout << ans << '\n';

    return 0;
}

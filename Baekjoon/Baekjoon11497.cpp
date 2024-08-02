// Baekjoon11497.cpp
#include <iostream>

#include <algorithm>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

void solve() {
    int n;
    cin >> n;

    int log[10'000];
    for (int i = 0; i < n; i++)
        cin >> log[i];
    sort(log, log + n);

    int arr[10'000];
    int left = 0, right = n - 1;

    for (int i = 0; i < n; i++)
        (i % 2 == 0) ? arr[left++] = log[i] : arr[right--] = log[i];
    
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans = max(ans, ABS(arr[i + 1] - arr[i]));
    ans = max(ans, ABS(arr[n - 1] - arr[0]));

    cout << ans << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
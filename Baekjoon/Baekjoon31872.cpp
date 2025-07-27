// Baekjoon31872.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int arr[100'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    ll ans = arr[0];
    int diff[100'000] = { arr[0], };
    for (int i = 1; i < n; i++) {
        diff[i] = arr[i] - arr[i - 1];
        ans = ans + diff[i];
    }
    sort(diff, diff + n, greater<int>());

    for (int i = 0; i < k; i++)
        ans -= diff[i];

    cout << ans << '\n';

    return 0;
}

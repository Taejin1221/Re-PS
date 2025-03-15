// Baekjoon23330.cpp
#include <iostream>

#include <algorithm>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

using ll = long long;

int main(void) {
    ll n;
    cin >> n;

    ll arr[500'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    ll sum = 0LL;
    for (ll i = 0LL; i < n - 1; i++) {
        sum = sum + 2 * ABS(arr[i] - arr[i + 1]) * (i + 1) * (n - (i + 1));
    }

    cout << sum << '\n';

    return 0;
}

// Baekjoon28357.cpp
#include <iostream>

using namespace std;

using ll = long long;

ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    ll arr[500'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll left = -1, right = 1'000'000'000'000;
    while (left + 1 < right) {
        ll mid = (left + right) / 2;

        ll candy = 0LL;
        for (int i = 0; i < n; i++)
            candy += max(0LL, arr[i] - mid);

        if (candy > k)
            left = mid;
        else
            right = mid;
    }

    cout << right << '\n';

    return 0;
}

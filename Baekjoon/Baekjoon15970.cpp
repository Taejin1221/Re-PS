// Baekjoon15970.cpp
#include <iostream>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

using pii = pair<int, int>;
using ll = long long;

ll min(ll a, ll b) { return (a < b) ? a : b; }

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    pii arr[5'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    ll ans = 0LL;
    for (int i = 0; i < n; i++) {
        ll result = 0x3f3f3f3f;
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i].second == arr[j].second)
                result = min(result, ABS(arr[i].first - arr[j].first));
        }

        ans += result;
    }

    cout << ans << '\n';

    return 0;
}

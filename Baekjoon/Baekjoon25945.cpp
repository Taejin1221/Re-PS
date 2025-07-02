#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    ll sum = 0, arr[1'000'000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        sum += arr[i];
    }

    ll thr = sum / n;
    ll minus = 0, plus = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > thr)
            plus += arr[i] - (thr + 1);
        else if (arr[i] < thr)
            minus += thr - arr[i];
    }

    cout << max(minus, plus) << '\n';

    return 0;
}

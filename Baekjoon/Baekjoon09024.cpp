// Baekjoon09024.cpp
#include <iostream>

#include <map>
#include <algorithm>

using namespace std;

void solve(void) {
    int n, k;
    cin >> n >> k;

    int arr[1'000'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    map<int, int> record;
    for (int i = 0; i < n; i++) {
        int target = k - arr[i];
        int idx = lower_bound(arr, arr + n, target) - arr;

        int diff1 = 0x3f3f3f3f, diff2 = 0x3f3f3f3f;
        if (idx > 0 && (idx - 1) != i)
            diff1 = k - (arr[i] + arr[idx - 1]);

        if (idx < n && i != idx)
            diff2 = (arr[i] + arr[idx]) - k;

        int diff, cnt = 1;
        if (diff1 < diff2)
            diff = diff1;
        else if (diff1 > diff2)
            diff = diff2;
        else
            diff = diff1, cnt++;

        if (diff == 0x3f3f3f3f)
            continue;

        auto iter = record.find(diff);
        if (iter == record.end())
            record.insert({ diff, cnt });
        else
            iter->second += cnt;
    }

    int ans = record.begin()->second;
    cout << (ans % 2 ? ans : ans / 2) << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

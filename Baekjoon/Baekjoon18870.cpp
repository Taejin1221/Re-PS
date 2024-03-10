// Baekjoon18870.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> query(n), arr(n);
    for (int i = 0; i < n; i++) {
        cin >> query[i];
        arr[i] = query[i];
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(arr.begin(), arr.end(), query[i]) - arr.begin();
        cout << idx << ' ';
    }
    cout << '\n';

    return 0;
}
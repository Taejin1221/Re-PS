// Baekjoon11637.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    int total = 0;
    vector<pii> arr;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        total += num;

        arr.push_back({ num, i });
    }
    sort(arr.begin(), arr.end());

    if (arr[n - 1].first == arr[n - 2].first)
        cout << "no winner";
    else {
        if (arr[n - 1].first > total / 2)
            cout << "majority";
        else
            cout << "minority";
        cout << " winner " << arr[n - 1].second;
    }
    cout << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
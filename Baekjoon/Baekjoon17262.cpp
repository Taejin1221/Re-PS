// Baekjoon17262.cpp
#include <iostream>

#include <algorithm>

using namespace std;

using pii = pair<int, int>;

bool compare2(const pii& a, const pii& b) {
    return a.second < b.second;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    pii arr[100'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);
    int end = arr[n - 1].first;

    sort(arr, arr + n, compare2);
    int start = arr[0].second;

    int ans = end - start;
    cout << (ans <= 0 ? 0 : ans) << '\n';

    return 0;
}
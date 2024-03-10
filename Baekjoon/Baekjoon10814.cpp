// Baekjoon10814.cpp
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using pis = pair<int, string>;

bool compare(const pis& a, const pis& b) {
    return a.first < b.first;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pis> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    stable_sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < n; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';

    return 0;
}
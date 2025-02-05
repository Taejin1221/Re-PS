// Baekjoon26265.cpp
#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

using pss = pair<string, string>;

bool compare(pss& a, pss& b) {
    if (a.first == b.first)
        return a.second > b.second;
    else
        return a.first < b.first;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    pss arr[100'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n, compare);

    for (int i = 0; i < n; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';

    return 0;
}

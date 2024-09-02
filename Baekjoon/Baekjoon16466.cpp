// Baekjoon16466.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[1'000'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int ans = 1;
    for (int i = 0; arr[i] == ans; i++)
        ans++;

    cout << ans << '\n';

    return 0;
}
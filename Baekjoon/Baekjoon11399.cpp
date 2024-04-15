// Baekjoon11399.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];

        ans += sum;
    }

    cout << ans << '\n';
}
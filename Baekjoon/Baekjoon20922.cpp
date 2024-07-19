// Baekjoon20922.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int arr[200'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int table[100'001] = { 0, };
    int ans = 0, left = 0;
    for (int right = 0; right < n; right++) {
        table[arr[right]]++;
        while (table[arr[right]] > k) {
            table[arr[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    cout << ans << '\n';

    return 0;
}
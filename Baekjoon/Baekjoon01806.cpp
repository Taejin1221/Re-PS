// Baekjoon01806.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    int arr[100'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 0, currS = 0, ans = 0x3f3f3f3f;
    for (int right = 0; right < n; right++) {
        currS += arr[right];
        while (left <= right && currS >= s) {
            ans = min(ans, right - left + 1);
            currS -= arr[left];
            left++;
        }
    }

    if (ans == 0x3f3f3f3f)
        cout << 0;
    else
        cout << ans;
    cout << '\n';

    return 0;
}
// Baekjoon06159.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, s;
    cin >> n >> s;

    int ans = 0;
    int arr[20'000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = i - 1; j >= 0; j--)
            if (arr[i] + arr[j] <= s)
                ans++;
    }

    cout << ans << '\n';

    return 0;
}

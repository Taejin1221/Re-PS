// Baekjoon02559.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int arr[100'000];
    int ans = -0x3f3f3f3f, sum = 0, num = 0;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];

        sum += arr[i];
        num++;

        if (num == k) {
            ans = max(ans, sum);
            sum -= arr[i - (k - 1)];
            num--;
        }
    }

    cout << ans << '\n';

    return 0;
}

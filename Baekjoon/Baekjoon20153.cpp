// Baekjoon20153.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[2'222];
    int total[25] = { 0, };
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < 25; j++) {
            if (((1 << j) & arr[i]) > 0)
                total[j]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < 25; i++) {
        if (total[i] % 2 == 1)
            ans += (1 << i);
    }

    for (int i = 0; i < n; i++) {
        int result = 0;
        for (int j = 0; j < 25; j++) {
            int x = total[j];
            if (((1 << j) & arr[i]) > 0)
                x--;

            if (x % 2 == 1)
                result += (1 << j);
        }

        ans = max(ans, result);
    }

    cout << ans << ans << '\n';

    return 0;
}

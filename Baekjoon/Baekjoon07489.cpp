// Baekjoon07489.cpp
#include <iostream>

using namespace std;

int main(void) {
    int ans[1'001] = { 1, 1, };
    for (int i = 2; i <= 1'000; i++) {
        int curr = ans[i - 1] * i;

        while (curr % 10 == 0) {
            curr /= 10;
        }

        ans[i] = curr % 1000;
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << ans[n] % 10 << '\n';
    }

    return 0;
}
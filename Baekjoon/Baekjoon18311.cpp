// Baekjoon18311.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; ll k;
    cin >> n >> k;

    ll lengthSum = 0LL;
    int courseLength[100'000], ans = -1;
    for (int i = 0; i < n; i++) {
        cin >> courseLength[i];

        lengthSum += courseLength[i];
        if (ans == -1 && k < lengthSum)
            ans = i + 1;
    }

    if (ans == -1) {
        for (int i = n - 1; i >= 0; i--) {
            lengthSum += courseLength[i];
            if (ans == -1 && k < lengthSum) {
                ans = i + 1;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
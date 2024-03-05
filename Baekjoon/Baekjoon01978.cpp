// Baekjoon01978.cpp
#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    int ans = 0;
    while (t--) {
        int n;
        cin >> n;

        bool isPrime = true;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }

        ans += (n != 1 && isPrime ? 1 : 0);
    }

    cout << ans << '\n';

    return 0;
}
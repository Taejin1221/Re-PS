// Baekjoon15953.cpp
#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ans = 0;
        if (n <= 0)
            ans += 0;
        else if (n <= 1)
            ans += 5'000'000;
        else if (n <= 3)
            ans += 3'000'000;
        else if (n <= 6)
            ans += 2'000'000;
        else if (n <= 10)
            ans += 500'000;
        else if (n <= 15)
            ans += 300'000;
        else if (n <= 21)
            ans += 100'000;

        cin >> n;
        if (n <= 0)
            ans += 0;
        else if (n <= 1)
            ans += 5'120'000;
        else if (n <= 3)
            ans += 2'560'000;
        else if (n <= 7)
            ans += 1'280'000;
        else if (n <= 15)
            ans += 640'000;
        else if (n <= 31)
            ans += 320'000;

        cout << ans << '\n';
    }

    return 0;
}

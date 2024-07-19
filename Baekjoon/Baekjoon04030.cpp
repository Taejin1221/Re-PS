// Baekjoon04030.cpp
#include <iostream>

using namespace std;

using ll = long long; 

void solve(int a, int b) {
    int ans = 0;

    int j = 1; ll sum = 0LL;
    for (int i = 1; i * i < b && i * i <= 1'000'000'000; i++) {
        int square = i * i;
        if (square > a) {
            while (sum < square)
                sum += j++;

            if (square - 1 == sum - (j - 1))
                ans++;
        }
    }

    cout << ans << '\n';
}

int main(void) {
    int a, b;
    cin >> a >> b;

    for (int i = 1; a != 0 && b != 0; i++) {
        cout << "Case " << i << ": ";
        solve(a, b);

        cin >> a >> b;
    }

    return 0;
}
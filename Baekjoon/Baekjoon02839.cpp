// Baekjoon02839.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= 1'000; i++) {
        for (int j = 0; j <= 1'000; j++) {
            if (i * 5 + j * 3 == n)
                ans = min(ans, i + j);
        }
    }

    cout << ((ans == 0x3f3f3f3f) ? -1 : ans) << '\n';

    return 0;
}
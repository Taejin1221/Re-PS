// Baekjoon31962.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;

    int ans = -1;
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;

        if (s + t <= x)
            ans = max(ans, s);
    }

    cout << ans << '\n';

    return 0;
}

// Baekjoon27222.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    bool workout[1'000];
    for (int i = 0; i < n; i++)
        cin >> workout[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (workout[i])
            ans += max(0, y - x);
    }

    cout << ans << '\n';

    return 0;
}

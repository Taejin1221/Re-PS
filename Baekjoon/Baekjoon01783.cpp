// Baekjoon01783.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    if (n == 1)
        ans = 1;
    else if (n == 2) {
        if (m < 3)
            ans = 1;
        else if (m < 5)
            ans = 2;
        else if (m < 7)
            ans = 3;
        else
            ans = 4;
    } else {
        if (m == 1)
            ans = 1;
        else if (m == 2)
            ans = 2;
        else if (m == 3)
            ans = 3;
        else if (m <= 6)
            ans = 4;
        else
            ans = 5 + (m - 7);
    }

    cout << ans << '\n';

    return 0;
}

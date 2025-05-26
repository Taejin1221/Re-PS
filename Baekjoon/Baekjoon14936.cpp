// Baekjoon14936.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    if (m == 0)
        cout << 1;
    else {
        if (n == 1)
            cout << 2;
        else if (n == 2)
            cout << (m == 1 ? 3 : 4);
        else {
            int ans = (
                1
                + (m >= n) // 동작 1
                + (m >= n / 2) // 동작 2
                + (m >= (n + 1) / 2) // 동작 3
                + (m >= (n + 2) / 3) // 동작 4
                + (m >= n + (n + 2) / 3) // 동작 1, 4
                + (m >= ((n / 2) + (n + 2) / 3)) // 동작 2, 4
                + (m >= (n + 1) / 2 + (n + 2) / 3) // 동작 3, 4
            );
    
            cout << ans;
        }
    }

    cout << '\n';

    return 0;
}

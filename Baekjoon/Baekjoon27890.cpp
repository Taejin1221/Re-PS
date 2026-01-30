// Baekjoon27890.cpp
#include <iostream>

using namespace std;

int main(void) {
    int ans, n;
    cin >> ans >> n;

    while (n--)
        ans = ((ans % 2 == 0) ? (ans / 2) : (2 * ans)) ^ 6;
    cout << ans << '\n';

    return 0;
}

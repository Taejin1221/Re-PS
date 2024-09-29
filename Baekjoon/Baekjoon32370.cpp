// Baekjoon32370.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int ans;
    if (a == 0 || b == 0) {
        if (((a == 0 && x == 0) && y < b) || ((b == 0 && y == 0) && x < a))
            ans = 3;
        else
            ans = 1;
    } else
        ans = 2;

    cout << ans << '\n';

    return 0;
}
// Baekjoon01075.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, f;
    cin >> n >> f;

    n /= 100;
    n *= 100;

    int ans = 0;
    for (ans = 0; ans <= 99 && (n + ans) % f != 0; ans++);

    if (ans < 10)
        cout << '0';
    cout << ans << '\n';

    return 0;
}
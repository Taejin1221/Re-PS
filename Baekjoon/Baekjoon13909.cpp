// Baekjoon13909.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int ans;
    for (ans = 1; ans * ans <= n; ans++);

    cout << ans - 1 << '\n';

    return 0;
}
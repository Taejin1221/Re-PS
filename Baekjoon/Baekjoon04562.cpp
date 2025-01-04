// Baekjoon04562.cpp
#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        cout << (x >= y ? "MMM BRAINS" : "NO BRAINS") << '\n';
    }

    return 0;
}

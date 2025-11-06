// Baekjoon01057.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, a, b;
    cin >> n >> a >> b;

    int ans = 1;
    while (a != b) {
        int nextA = (a + 1) / 2, nextB = (b + 1) / 2;
        if (nextA == nextB)
            break;

        a = nextA, b = nextB;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}

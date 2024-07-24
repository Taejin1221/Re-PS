// Baekjoon30394.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int minY = 0x3f3f3f3f, maxY = -0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    cout << maxY - minY << '\n';

    return 0;
}
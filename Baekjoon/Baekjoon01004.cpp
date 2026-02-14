// Baekjoon01004.cpp
#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n;
        cin >> n;

        int ans = 0;
        while (n--) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            bool in1 = false, in2 = false;

            int dSquare = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
            if (dSquare < r * r)
                in1 = true;

            dSquare = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);
            if (dSquare < r * r)
                in2 = true;

            if (in1 ^ in2)
                ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}

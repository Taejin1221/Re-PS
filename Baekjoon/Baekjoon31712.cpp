#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c1, c2, c3, d1, d2, d3;
    cin >> c1 >> d1 >> c2 >> d2 >> c3 >> d3;

    int h;
    cin >> h;

    h -= (d1 + d2 + d3);

    int t = 0;
    while (h > 0) {
        t++;
        if (t % c1 == 0)
            h -= d1;

        if (t % c2 == 0)
            h -= d2;

        if (t % c3 == 0)
            h -= d3;
    }
    cout << t << '\n';

    return 0;
}

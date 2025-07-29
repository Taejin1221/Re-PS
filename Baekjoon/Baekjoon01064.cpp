// Baekjoon01064.cpp
#include <iostream>

#include <cmath>

using namespace std;

using pii = pair<int, int>;

int getGCD(int a, int b) {
    return (b ? getGCD(b, a % b) : a);
}

int getDistance2(pii a, pii b) {
    int x = a.first - b.first, y = a.second - b.second;
    return (x * x + y * y);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pii a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;

    int deltaX1 = a.first - b.first, deltaY1 = a.second - b.second;
    int deltaX2 = b.first - c.first, deltaY2 = b.second - c.second;

    double ans = 0.0;
    if ((deltaX1 == 0 && deltaX2 == 0) || (deltaY1 == 0 && deltaY2 == 0))
        ans = -1.0;
    else if ((deltaX1 != 0 && deltaX2 != 0) || (deltaY1 != 0 && deltaY2 != 0)) {
        int gcd1 = (deltaX1 > deltaY1 ? getGCD(deltaX1, deltaY1) : getGCD(deltaY1, deltaX1)),
            gcd2 = (deltaX2 > deltaY2 ? getGCD(deltaX2, deltaY2) : getGCD(deltaY2, deltaX2));

        if ((deltaX1 / gcd1 == deltaX2 / gcd2) && (deltaY1 / gcd1 == deltaY2 / gcd2))
            ans = -1.0;
    }

    if (ans != -1.0) {
        int ab = getDistance2(a, b), bc = getDistance2(b, c), ca = getDistance2(c, a);

        int big, small;
        if (ab >= bc && bc >= ca)
            big = ab, small = ca;
        else if (ab >= ca && ca >= bc)
            big = ab, small = bc;
        else if (bc >= ab && ab >= ca)
            big = bc, small = ca;
        else if (bc >= ca && ca >= ab)
            big = bc, small = ab;
        else if (ca >= ab && ab >= bc)
            big = ca, small = bc;
        else
            big = ca, small = ab;

        ans = (sqrt(big) - sqrt(small)) * 2.0;
    }

    cout << fixed;
    cout.precision(9);

    cout << ans << '\n';

    return 0;
}

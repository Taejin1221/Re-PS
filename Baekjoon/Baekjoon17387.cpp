// Baekjoon17387.cpp
#include <iostream>

using namespace std;

using ll = long long;

struct Point {
    ll x, y;

    Point(): x(0), y(0) { }

    bool operator<=(const Point& l2) const {
        return (x <= l2.x && y <= l2.y);
    }
};

int getCCW(Point a, Point b, Point c) {
    ll result = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    if (result > 0LL)
        return 1;
    else if (result < 0LL)
        return -1;
    else
        return 0;
}

int main(void) {
    Point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;

    if (getCCW(a, b, c) == 0 && getCCW(a, b, d) == 0) {
        int left = min(a.x, b.x), right = max(a.x, b.x), bottom = min(a.y, b.y), top = max(a.y, b.y);

        if (((left <= c.x && c.x <= right) && (bottom <= c.y && c.y <= top)) || ((left <= d.x && d.x <= right) && (bottom <= d.y && d.y <= top)))
            cout << 1;
        else {
            left = min(c.x, d.x), right = max(c.x, d.x), bottom = min(c.y, d.y), top = max(c.y, d.y);
            if (((left <= a.x && a.x <= right) && (bottom <= a.y && a.y <= top)) || ((left <= b.x && b.x <= right) && (bottom <= b.y && b.y <= top)))
                cout << 1;
            else
                cout << 0;
        }
    } else if (getCCW(a, b, c) * getCCW(a, b, d) <= 0 && getCCW(c, d, a) * getCCW(c, d, b) <= 0)
        cout << 1;
    else
        cout << 0;
    cout << '\n';

    return 0;
}

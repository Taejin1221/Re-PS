// Baekjoon02166.cpp
#include <iostream>

using namespace std;

using ll = long long;

struct Point {
    ll x, y;
    Point(int x, int y): x(x), y(y) { }
    Point(): x(0), y(0) { }
};

ll getCrossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll area = 0LL;
    
    Point base;
    cin >> base.x >> base.y;

    Point prev;
    cin >> prev.x >> prev.y;

    Point curr;
    cin >> curr.x >> curr.y;

    area += getCrossProduct(base, prev, curr);
    prev = curr;

    for (int i = 3; i < n; i++) {
        cin >> curr.x >> curr.y;
        area += getCrossProduct(base, prev, curr);
        prev = curr;
    }

    if (area < 0)
        area *= -1;

    cout << fixed;
    cout.precision(1);

    cout << ((double)area / 2) << '\n';

    return 0;
}
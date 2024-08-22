// Baekjoon15803.cpp
#include <iostream>

#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int getGCD(int a, int b) {
    return b ? getGCD(b, a % b) : a;
}

int main(void) {
    pii points[3];
    cin >> points[0].first >> points[0].second;
    cin >> points[1].first >> points[1].second;
    cin >> points[2].first >> points[2].second;

    sort(points, points + 3);

    pii gradient1 = { (points[1].second - points[0].second), (points[1].first - points[0].first) };
    pii gradient2 = { (points[2].second - points[1].second), (points[2].first - points[1].first) };

    int gcd1 = gradient1.first > gradient1.second ? getGCD(gradient1.first, gradient1.second) : getGCD(gradient1.second, gradient1.first);
    int gcd2 = gradient2.first > gradient2.second ? getGCD(gradient2.first, gradient2.second) : getGCD(gradient2.second, gradient2.first);

    bool ans = true;
    if ((gradient1.first / gcd1 == gradient2.first / gcd2) && (gradient1.second / gcd1 == gradient2.second / gcd2))
        ans = false;

    if (ans)
        cout << "WINNER WINNER CHICKEN DINNER!";
    else
        cout << "WHERE IS MY CHICKEN?";
    cout << '\n';

    return 0;
}
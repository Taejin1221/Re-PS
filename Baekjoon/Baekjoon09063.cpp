// Baekjoon09063.cpp
#include <iostream>

#define abs(x) ((x) < 0 ? -(x) : (x))

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    pii leftBottom = { 10'000, 10'000 }, rightTop = { -10'000, -10'000 };
    for (int i = 0; i < n; i++) {
        pii curr;
        cin >> curr.first >> curr.second;

        leftBottom.first = min(leftBottom.first, curr.first);
        leftBottom.second = min(leftBottom.second, curr.second);

        rightTop.first = max(rightTop.first, curr.first);
        rightTop.second = max(rightTop.second, curr.second);
    }

    cout << (abs(rightTop.first - leftBottom.first) * abs(rightTop.second - leftBottom.second)) << '\n';

    return 0;
}
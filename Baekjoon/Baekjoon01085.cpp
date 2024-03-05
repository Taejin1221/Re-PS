// Baekjoon01085.cpp
#include <iostream>

using namespace std;

int main(void) {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    cout << min(min(x, w - x), min(y, h - y)) << '\n';

    return 0;
}
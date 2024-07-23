// Baekjoon32025.cpp
#include <iostream>

using namespace std;

int main(void) {
    int h, w;
    cin >> h >> w;

    int diameter = min(h * 100, w * 100);
    cout << diameter / 2 << '\n';

    return 0;
}
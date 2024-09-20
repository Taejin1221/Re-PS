// Baekjoon29751.cpp
#include <iostream>

using namespace std;

int main(void) {
    double w, h;
    cin >> w >> h;

    cout.precision(1);

    cout << fixed;
    cout << w * h / 2 << '\n';

    return 0;
}
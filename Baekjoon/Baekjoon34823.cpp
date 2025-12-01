// Baekjoon34823.cpp
#include <iostream>

using namespace std;

int main(void) {
    int y, c, p;
    cin >> y >> c >> p;

    cout << min(y, min(c / 2, p)) << '\n';

    return 0;
}
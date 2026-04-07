// Baekjoon01712.cpp
#include <iostream>

using namespace std;

// a + b * x < c * x 를 만족하는 가장 작은 x
// a < x (c - b)
// a / (c - b) < x

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;

    if (c > b)
        cout << (a / (c - b) + 1);
    else
        cout << -1;
    cout << '\n';

    return 0;
}

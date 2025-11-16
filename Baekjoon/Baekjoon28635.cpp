// Baekjoon28635.cpp
#include <iostream>

using namespace std;

int main(void) {
    int m, a, b;
    cin >> m >> a >> b;

    if (b >= a)
        cout << (b - a);
    else
        cout << (b - a + m);
    cout << '\n';

    return 0;
}

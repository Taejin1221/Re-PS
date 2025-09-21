// Baekjoon14489.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    int c;
    cin >> c;

    if (c * 2 <= a + b)
        cout << ((a + b) - c * 2);
    else
        cout << (a + b);
    cout << '\n';

    return 0;
}

// Baekjoon33170.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c <= 21)
        cout << 1;
    else
        cout << 0;
    cout << '\n';

    return 0;
}

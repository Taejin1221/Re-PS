// Baekjoon02480.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;

    int result;
    if (a == b && b == c)
        result = 10000 + a * 1000;
    else if (a == b || b == c || c == a)
        result = 1000 + ((a == b) ? a : c) * 100;
    else
        result = 100 * max(a, max(b, c));

    cout << result << '\n';

    return 0;
}
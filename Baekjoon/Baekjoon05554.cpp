// Baekjoon05554.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int sum = a + b + c + d;
    cout << sum / 60 << '\n';
    cout << sum % 60 << '\n';

    return 0;
}

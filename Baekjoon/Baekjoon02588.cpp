// Baekjoon02588.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    int result = a * b;
    cout << a * (b % 10) << '\n';
    b /= 10;
    cout << a * (b % 10) << '\n';
    b /= 10;
    cout << a * (b % 10) << '\n';
    cout << result << '\n';

    return 0;
}
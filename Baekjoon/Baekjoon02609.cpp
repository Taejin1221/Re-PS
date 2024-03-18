// Baekjoon02609.cpp
#include <iostream>

using namespace std;

int getGCD(int a, int b) {
    return (a % b) ? getGCD(b, a % b) : b;
}

int main(void) {
    int a, b;
    cin >> a >> b;

    int gcd = (a > b) ? getGCD(a, b) : getGCD(b, a);
    cout << gcd << '\n' << a * b / gcd << '\n';

    return 0;
}
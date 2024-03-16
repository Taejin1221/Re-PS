// Baekjoon01735.cpp
#include <iostream>

using namespace std;

int getGCD(int a, int b) {
    return (a % b) ? getGCD(b, a % b) : b;
}

int main(void) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int numerator = a * d + c * b, denominator = b * d;
    int gcd = (numerator < denominator) ? getGCD(denominator, numerator) : getGCD(numerator, denominator);
    cout << numerator / gcd << ' ' << denominator / gcd << '\n';

    return 0;
}
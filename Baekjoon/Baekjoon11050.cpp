// Baekjoon11050.cpp
#include <iostream>

using namespace std;

int fac(int n) {
    return (n ? fac(n - 1) * n : 1);
}

int main(void) {
    int n, k;
    cin >> n >> k;

    cout << fac(n) / (fac(n - k) * fac(k)) << '\n';

    return 0;
}
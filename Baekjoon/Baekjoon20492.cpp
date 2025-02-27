// Baekjoon20492.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    cout << n * 78 / 100 << ' ';
    cout << n / 1000 * 800 + n / 1000 * 156 << '\n';

    return 0;
}
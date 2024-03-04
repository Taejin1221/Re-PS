// Baekjoon02903.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    cout << ((1 << n) + 1) * ((1 << n) + 1) << '\n';

    return 0;
}
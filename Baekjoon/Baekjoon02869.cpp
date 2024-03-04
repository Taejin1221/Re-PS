// Baekjoon02869.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, v;
    cin >> a >> b >> v;

    cout << (v == a ? 1 : (v - a - 1) / (a - b) + 2) << '\n';

    return 0;
}
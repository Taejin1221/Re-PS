// Baekjoon02292.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int i = 0;
    while (n > i * (i + 1) / 2 * 6 + 1)
        i++;

    cout << i + 1 << '\n';

    return 0;
}
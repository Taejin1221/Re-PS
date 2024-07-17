// Baekjoon02097.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int a = 1, b = 1;
    while ((a + 1) * (b + 1) < n) {
        if (a == b)
            a++;
        else
            b++;
    }

    cout << (a + b) * 2 << '\n';

    return 0;
}
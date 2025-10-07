// Baekjoon17256.cpp
#include <iostream>

using namespace std;

int main(void) {
    int ax, ay, az;
    cin >> ax >> ay >> az;

    int cx, cy, cz;
    cin >> cx >> cy >> cz;

    cout << (cx - az) << ' ' << (cy / ay) << ' ' << (cz - ax) << '\n';

    return 0;
}

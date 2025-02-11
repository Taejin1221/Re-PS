// Baekjoon17009.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    int aScore = a1 * 3 + a2 * 2 + a3, bScore = b1 * 3 + b2 * 2 + b3;
    if (aScore > bScore)
        cout << 'A';
    else if (bScore > aScore)
        cout << 'B';
    else
        cout << 'T';
    cout << '\n';

    return 0;
}

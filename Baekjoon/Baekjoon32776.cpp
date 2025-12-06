// Baekjoon32776.cpp
#include <iostream>

using namespace std;

int main(void) {
    int s;
    cin >> s;

    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    if (s <= 240 || s <= (a1 + a2 + a3))
        cout << "high speed rail";
    else
        cout << "flight";
    cout << '\n';

    return 0;
}

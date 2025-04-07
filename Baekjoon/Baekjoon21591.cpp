// Baekjoon21591.cpp
#include <iostream>

using namespace std;

int main(void) {
    int wc, hc, ws, hs;
    cin >> wc >> hc >> ws >> hs;

    if (wc - ws <= 1 || hc - hs <= 1)
        cout << 0;
    else
        cout << 1;
    cout << '\n';

    return 0;
}

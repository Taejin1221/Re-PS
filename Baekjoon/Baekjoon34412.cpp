// Baekjoon34412.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    if (n >= 13)
        cout << (n + 1);
    else
        cout << n;
    cout << '\n';

    return 0;
}

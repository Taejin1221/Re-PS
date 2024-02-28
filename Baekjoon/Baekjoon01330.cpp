// Baekjoon01330.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    if (a > b)
        cout << '>';
    else if (a < b)
        cout << '<';
    else
        cout << "==";
    cout << '\n';

    return 0;
}
// Baekjoon28113.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, a, b;
    cin >> n >> a >> b;

    if (a < b)
        cout << "Bus";
    else if (a > b)
        cout << "Subway";
    else
        cout << "Anything";
    cout << '\n';

    return 0;
}
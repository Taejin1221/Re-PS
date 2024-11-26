// Baekjoon04999.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string a, b;
    cin >> a >> b;

    if (a.size() >= b.size())
        cout << "go";
    else
        cout << "no";
    cout << '\n';

    return 0;
}

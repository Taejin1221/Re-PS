// Baekjoon04806.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int ans = 0;

    string str;
    while (getline(cin, str))
        ans++;

    cout << ans << '\n';

    return 0;
}

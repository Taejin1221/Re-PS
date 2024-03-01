// Baekjoon09086.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        cout << str.front() << str.back() << '\n';
    }

    return 0;
}
// Baekjoon10953.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;

        int a = str[0] - '0', b = str[2] - '0';
        cout << a + b << '\n';
    }

    return 0;
}

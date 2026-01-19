// Baekjoon15873.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int a, b;
    if (str.size() == 2) {
        a = str[0] - '0';
        b = str[1] - '0';
    } else if (str.size() == 3) {
        if (str[1] == '0') {
            a = 10;
            b = str[2] - '0';
        } else {
            a = str[0] - '0';
            b = 10;
        }
    } else
        a = 10, b = 10;
    cout << a + b << '\n';

    return 0;
}

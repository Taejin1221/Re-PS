// Baekjoon10988.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int len = str.size();

    bool isPalindrome = true;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    cout << (isPalindrome ? 1 : 0) << '\n';

    return 0;
}
// Baekjoon01157.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int number[26] = { 0, };
    for (char c : str) {
        if ('a' <= c && c <= 'z')
            c -= 32;

        number[c - 'A']++;
    }

    pair<char, int> ans = { '\0', 0 };
    bool isDuplicated = false;
    for (int i = 0; i < 26; i++) {
        if (number[i] > ans.second) {
            ans = { 'A' + i, number[i]};

            isDuplicated = false;
        } else if (number[i] == ans.second) {
            isDuplicated = true;
        }
    }

    cout << (isDuplicated ? '?' : ans.first) << '\n';

    return 0;
}
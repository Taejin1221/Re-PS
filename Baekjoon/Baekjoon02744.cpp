// Baekjoon02744.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    for (char& c : str) {
        if ('a' <= c && c <= 'z')
            cout << (char)(c - 32);
        else
            cout << (char)(c + 32);
    }
    cout << '\n';

    return 0;
}
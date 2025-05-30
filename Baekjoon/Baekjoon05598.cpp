// Baekjoon05598.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        int diff = str[i] - 'A' - 3;
        if (diff < 0)
            diff += 26;
        cout << (char)('A' + diff);
    }
    cout << '\n';

    return 0;
}
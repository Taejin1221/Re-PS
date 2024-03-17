// Baekjoon04949.cpp
#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool isVPS(string& str) {
    vector<char> stck;
    for (char& s : str) {
        if (s == '(' || s == '[')
            stck.push_back(s);
        else if (s == ')') {
            if (stck.size() != 0 && stck.back() == '(')
                stck.pop_back();
            else
                return false;
        } else if (s == ']') {
            if (stck.size() != 0 && stck.back() == '[')
                stck.pop_back();
            else
                return false;
        }
    }

    return (stck.size() == 0) ? true : false;
}

int main(void) {
    string str;
    getline(cin, str);

    while (str != ".") {
        cout << (isVPS(str) ? "yes" : "no") << '\n';

        getline(cin, str);
    }

    return 0;
}
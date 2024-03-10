// Baekjoon11478.cpp
#include <iostream>

#include <set>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int n = str.size();

    set<string> substr;
    for (int i = 0; i < n; i++) {
        string curr;
        for (int j = 0; i + j < n; j++) {
            curr.push_back(str[i + j]);

            substr.insert(curr);
        }
    }

    cout << substr.size() << '\n';

    return 0;
}
// Baekjoon11721.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int n = (int)str.size();

    for (int i = 0; i < n; i += 10) {
        for (int j = 0; (i + j) < n && j < 10; j++)
            cout << str[i + j];
        cout << '\n';
    }

    return 0;
}

// Baekjoon32399.cpp
#include <iostream>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    if (str == "(1)")
        cout << 0;
    else if (str == "()1")
        cout << 1;
    else if (str == ")1(")
        cout << 2;
    else if (str == ")(1")
        cout << 1;
    else if (str == "1()")
        cout << 1;
    else if (str == "1)(")
        cout << 1;
    cout << '\n';

    return 0;
}
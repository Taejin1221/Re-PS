// Baekjoon33651.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string uapc;
    cin >> uapc;

    string ans = "UAPC";
    for (char& a : ans) {
        bool isIn = false;
        for (char& u : uapc) {
            if (u == a) {
                isIn = true;
                break;
            }
        }

        if (!isIn)
            cout << a;
    }

    cout << '\n';

    return 0;
}

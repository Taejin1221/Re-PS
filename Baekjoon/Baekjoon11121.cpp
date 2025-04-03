// Baekjoon11121.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        if (a == b)
            cout << "OK";
        else
            cout << "ERROR";
        cout << '\n';
    }

    return 0;
}

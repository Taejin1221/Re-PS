// Baekjoon34408.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string s, t;
    cin >> s >> t;

    int original[26] = { 0, };
    for (char a : s)
        original[(a - 'A')]++;

    bool ans = true;
    for (char a : t) {
        int target = a - 'A';
        if (original[target] == 0) {
            ans = false;
            break;
        }

        original[target]--;
    }

    cout << (ans ? "OK" : "NEED FIX") << '\n';

    return 0;
}

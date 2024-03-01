// Baekjooon01152.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int ans = 0;
    while (!cin.eof()) {
        string str;
        cin >> str;

        if (str[0] != '\0')
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
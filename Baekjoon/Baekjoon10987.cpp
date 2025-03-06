// Baekjoon10987.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int ans = 0;
    for (char& c : str)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            ans++;

    cout << ans << '\n';

    return 0;
}

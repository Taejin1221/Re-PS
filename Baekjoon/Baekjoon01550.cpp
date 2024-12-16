// Baekjoon01550.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int ans = 0, exp = 1;
    for (int i = str.size() - 1; i >= 0; i--) {
        int num;
        if ('0' <= str[i] && str[i] <= '9')
            num = str[i] - '0';
        else
            num = str[i] - 'A' + 10;

        ans += num * exp;
        exp *= 16;
    }

    cout << ans << '\n';

    return 0;
}

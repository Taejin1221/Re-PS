// Baekjoon14626.cpp
#include <iostream>

#include <string>

using namespace std;

bool solve(string& str, char target) {
    int result = 0;
    for (int i = 0; i < 13; i++)
        result += ((str[i] != '*' ? str[i] : target) - '0') * (i % 2 ? 3 : 1);

    return (result % 10 == 0);
}

int main(void) {
    string str;
    cin >> str;

    char ans;
    for (int i = '0'; i <= '9'; i++) {
        if (solve(str, i)) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}

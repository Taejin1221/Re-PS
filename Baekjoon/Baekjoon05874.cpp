// Baekjoon05874.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int ans = 0, back = 0;
    bool flag = false;
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] == '(' && str[i + 1] == '(')
            back++;
        else if (str[i] == ')' && str[i + 1] == ')')
            ans += back;
    }

    cout << ans << '\n';

    return 0;
}

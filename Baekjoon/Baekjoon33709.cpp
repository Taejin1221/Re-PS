// Baekjoon33709.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    string str;
    cin >> str;

    int ans = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != '.' && str[i] != '|' && str[i] != ':' && str[i] != '#')
            curr = curr * 10 + (str[i] - '0');
        else {
            ans += curr;
            curr = 0;
        }
    }
    ans += curr;

    cout << ans << '\n';

    return 0;
}

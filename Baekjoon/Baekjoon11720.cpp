// Baekjoon11720.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += str[i] - '0';

    cout << ans << '\n';

    return 0;
}
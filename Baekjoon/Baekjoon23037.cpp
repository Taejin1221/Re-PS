// Baekjoon23037.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        int n = str[i] - '0';

        int result = 1;
        for (int j = 0; j < 5; j++)
            result *= n;

        ans += result;
    }

    cout << ans << '\n';
}

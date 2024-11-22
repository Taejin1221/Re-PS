// Baekjoon30045.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int ans = 0;
    while (n--) {
        string str;
        cin >> str;

        for (int i = 0; i < str.size() - 1; i++)
            if ((str[i] == '0' && str[i + 1] == '1') || (str[i] == 'O' && str[i + 1] == 'I')) {
                ans += 1;
                break;
            }
    }

    cout << ans << '\n';

    return 0;
}

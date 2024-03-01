// Baekjoon02941.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int len = str.size();

    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (i < len - 1) {
            if ((str[i] == 'c' && str[i + 1] == '=') ||
            (str[i] == 'c' && str[i + 1] == '-') ||
            (str[i] == 'd' && str[i + 1] == '-') ||
            (str[i] == 'l' && str[i + 1] == 'j') ||
            (str[i] == 'n' && str[i + 1] == 'j') ||
            (str[i] == 's' && str[i + 1] == '=') ||
            (str[i] == 'z' && str[i + 1] == '='))
                i++;
            else if (i < len - 2 && str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=')
                i += 2;
        }

        ans++;
    }

    cout << ans << '\n';

    return 0;
}
// Baekjoon01316.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    int ans = 0;
    while (t--) {
        bool check[26] = { false, };

        string str;
        cin >> str;

        int i = 0;
        bool isGroupWord = true;
        while (i < str.size()) {
            if (check[str[i] - 'a']) {
                isGroupWord = false;
                break;
            } else {
                char alphabet = str[i];
                check[alphabet - 'a'] = true;
                while (i < str.size() && str[i] == alphabet)
                    i++;
            }
        }

        ans += (isGroupWord ? 1 : 0);
    }

    cout << ans << '\n';

    return 0;
}
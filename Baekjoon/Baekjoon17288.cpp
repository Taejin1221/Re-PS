// Baekjoon17288.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    int n = str.size();

    int ans = 0;
    for (int i = 0; i <= n - 3; i++) {
        if (str[i] + 1 == str[i + 1]
            && str[i + 1] + 1 == str[i + 2]
            && (i + 3 >= n || str[i + 2] + 1 != str[i + 3])
            && (i - 1 < 0 || str[i - 1] + 1 != str[i])
        )
            ans++;
    }

    cout << ans << '\n';

    return 0;
}

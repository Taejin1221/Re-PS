// Baekjoon33810.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    string correct = "SciComLove";

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (str[i] != correct[i])
            ans++;
    }

    cout << ans << '\n';

    return 0;
}

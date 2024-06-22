// Baekjoon02774.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        string num;
        cin >> num;

        bool digit[10] = { false, };
        for (int i = 0; i < num.size(); i++) {
            digit[num[i] - '0'] = true;
        }

        int ans = 0;
        for (int i = 0; i < 10; i++)
            ans += digit[i];

        cout << ans << '\n';
    }

    return 0;
}

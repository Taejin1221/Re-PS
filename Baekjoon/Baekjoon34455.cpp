// Baekjoon34455.cpp
#include <iostream>

using namespace std;

int main(void) {
    int ans;
    cin >> ans;

    int t;
    cin >> t;
    while (t--) {
        char oper;
        cin >> oper;

        int n;
        cin >> n;

        if (oper == '+')
            ans += n;
        else
            ans -= n;
    }

    cout << ans << '\n';

    return 0;
}

// Baekjoon16114.cpp
#include <iostream>

using namespace std;

int main(void) {
    int x, n;
    cin >> x >> n;

    if(n == 0) {
        if (x > 0)
            cout << "INFINITE";
        else
            cout << 0;
    } else if (n == 1) {
        if (x < 0)
            cout << "INFINITE";
        else
            cout << 0;
    } else if (n % 2 == 1)
        cout << "ERROR";
    else {
        int ans = 0;
        for (int i = x - (n / 2); i > 0; i -= (n / 2))
            ans++;
        cout << ans;
    }
    cout << '\n';

    return 0;
}
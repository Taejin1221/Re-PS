// Baekjoon34400.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    while (n--) {
        int t;
        cin >> t;

        t %= 25;

        if (t < 17)
            cout << "ONLINE";
        else
            cout << "OFFLINE";
        cout << '\n';
    }

    return 0;
}

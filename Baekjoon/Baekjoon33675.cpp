// Baekjoon33675.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n % 2)
            cout << 0;
        else
            cout << (1LL << (n / 2));
        cout << '\n';
    }

    return 0;
}
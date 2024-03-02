// Baekjoon10250.cpp
#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int h, w, n;
        cin >> h >> w >> n;

        cout << (n % h ? n % h : h);

        int quot = (n - 1) / h + 1;
        if (quot < 10)
            cout << 0;
        cout << quot << '\n';
    }

    return 0;
}
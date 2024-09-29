// Baekjoon32369.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, a, b;
    cin >> n >> a >> b;

    int pos = 1, neg = 1;
    while (n--) {
        pos += a;
        neg += b;

        if (pos == neg)
            neg--;
        else if (pos < neg) {
            int temp = pos;
            pos = neg;
            neg = temp;
        }
    }

    cout << pos << ' ' << neg << '\n';

    return 0;
}
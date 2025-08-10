// Baekjoon02530.cpp
#include <iostream>

using namespace std;

int main(void) {
    int h, m, s;
    cin >> h >> m >> s;

    int d;
    cin >> d;

    s += d % 60;
    d /= 60;
    if (s >= 60) {
        m += s / 60;
        s %= 60;
    }

    m += d % 60;
    d /= 60;
    if (m >= 60) {
        h += m / 60;
        m %= 60;
    }

    h += d;
    if (h >= 24)
        h %= 24;

    cout << h << ' ' << m << ' ' << s << '\n';

    return 0;
}

// Baekjoon05575.cpp
#include <iostream>

using namespace std;

int main(void) {
    for (int i = 0; i < 3; i++) {
        int h1, m1, s1, h2, m2, s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

        int s3 = s2 - s1;
        int m3 = m2 - m1;
        int h3 = h2 - h1;

        if (s3 < 0) {
            m3--;
            s3 += 60;
        }

        if (m3 < 0) {
            h3--;
            m3 += 60;
        }

        cout << h3 << ' ' << m3 << ' ' << s3 << '\n';
    }

    return 0;
}
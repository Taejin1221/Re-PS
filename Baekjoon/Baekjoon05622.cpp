// Baekjoon05622.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string num;
    cin >> num;

    int dial[26];
    dial[0] = dial[1] = dial[2] = 3; // ABC;
    dial[3] = dial[4] = dial[5] = 4; // DEF;
    dial[6] = dial[7] = dial[8] = 5; // GHI;
    dial[9] = dial[10] = dial[11] = 6; // JKL;
    dial[12] = dial[13] = dial[14] = 7; // MNO;
    dial[15] = dial[16] = dial[17] = dial[18] = 8; // PQRS;
    dial[19] = dial[20] = dial[21] = 9; // TUV;
    dial[22] = dial[23] = dial[24] = dial[25] = 10; // WXYZ;

    int ans = 0;
    for (char& c : num)
        ans += dial[c - 'A'];

    cout << ans << '\n';

    return 0;
}
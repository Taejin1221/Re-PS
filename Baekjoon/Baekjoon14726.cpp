// Baekjoon14726.cpp
#include <iostream>

using namespace std;

void solve() {
    char cardNum1[17];
    cin >> cardNum1;

    int cardNum2[16], sum = 0;
    for (int i = 0; i < 16; i++) {
        cardNum2[i] = cardNum1[i] - '0';
        if (i % 2 == 0) {
            cardNum2[i] *= 2;
            if (cardNum2[i] >= 10)
                cardNum2[i] = cardNum2[i] / 10 + cardNum2[i] % 10;
        }

        sum += cardNum2[i];
    }

    cout << (sum % 10 == 0 ? 'T' : 'F') << '\n';
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
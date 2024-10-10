// Baekjoon01100.cpp
#include <iostream>

using namespace std;

int main(void) {
    int ans = 0;

    char board[9];
    for (int i = 0; i < 8; i++) {
        cin >> board;
        for (int j = (i % 2 == 0 ? 0 : 1); j < 8; j += 2)
            ans += board[j] == 'F';
    }

    cout << ans << '\n';

    return 0;
}
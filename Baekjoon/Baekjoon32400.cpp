// Baekjoon32400.cpp
#include <iostream>

using namespace std;

int main(void) {
    int bob = 0, board[20], idx20;
    for (int i = 0; i < 20; i++) {
        cin >> board[i];
        bob += board[i];
        if (board[i] == 20)
            idx20 = i;
    }

    int alice = board[idx20] + board[(idx20 - 1 + 20) % 20] + board[(idx20 + 1) % 20];
    alice *= 20;
    bob *= 3;

    if (alice > bob)
        cout << "Alice";
    else if (alice < bob)
        cout << "Bob";
    else
        cout << "Tie";
    cout << '\n';

    return 0;
}
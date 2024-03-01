// Baekjoon03003.cpp
#include <iostream>

using namespace std;

int main(void) {
    int answer[6] = { 1, 1, 2, 2, 2, 8 };
    for (int i = 0; i < 6; i++) {
        int curr;
        cin >> curr;

        cout << answer[i] - curr << ' ';
    }
    cout << '\n';

    return 0;
}
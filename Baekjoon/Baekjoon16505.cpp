// Baekjoon16505.cpp
#include <iostream>

using namespace std;

char stars[1024][1024] = { { '\0', }, };

void solve(int row, int col, int size) {
    if (size == 1)
        stars[row][col] = '*';
    else {
        int half = size / 2;
        solve(row, col, half);
        solve(row, col + half, half);
        solve(row + half, col, half);
    }
}

int main(void) {
    int n;
    cin >> n;

    int size = 1 << n;
    solve(0, 0, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++)
            cout << (stars[i][j] ? stars[i][j] : ' ');
        cout << '\n';
    }

    return 0;
}
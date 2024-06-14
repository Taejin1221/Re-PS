// Baekjoon09291.cpp
#include <iostream>

using namespace std;

int getMiniSquare(int row, int col) {
    return (row / 3 * 3 + col / 3);
}

void solve() {
    int sudoku[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> sudoku[i][j];
    
    bool isValid = true;
    bool table[3][9][10] = { { { false, }, }, };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int curr = sudoku[i][j], k = getMiniSquare(i, j);
            if (!table[0][i][curr] && !table[1][j][curr] && !table[2][k][curr])
                table[0][i][curr] = table[1][j][curr] = table[2][k][curr] = true;
            else {
                isValid = false;
                break;
            }
        }

        if (!isValid)
            break;
    }

    cout << (isValid ? "CORRECT" : "INCORRECT");
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}
// Baekjoon02775.cpp
#include <iostream>

using namespace std;

int main(void) {
    int apart[15][15] = {
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
    };

    for (int i = 1; i <= 14; i++)
        for (int j = 1; j <= 14; j++)
            apart[i][j] = apart[i][j - 1] + apart[i - 1][j];

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        cout << apart[n][k] << '\n';
    }

    return 0;
}
// Baekjoon01010.cpp
#include <iostream>

using namespace std;

int main(void) {
    int comb[31][31];
    for (int i = 1; i <= 30; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i - 1; j++)
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        comb[i][i] = 1;
    }

    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> r >> n;

        cout << comb[n][r] << '\n';
    }

    return 0;
}
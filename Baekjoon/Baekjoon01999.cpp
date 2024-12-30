// Baekjoon01999.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, b, k;
    cin >> n >> b >> k;

    int mat[250][250];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int ans[250][250];
    for (int i = 0; i < n - b + 1; i++) {
        int table[251] = { 0, };
        for (int j = 0; j < n ; j++) {
            if (j >= b)
                for (int k = 0; k < b; k++)
                    table[mat[i + k][j - b]]--;

            for (int k = 0; k < b; k++)
                table[mat[i + k][j]]++;

            if (j >= (b - 1)) {
                pii result = { 250, 0 }; // min, max
                for (int k = 0; k <= 250; k++) {
                    if (table[k]) {
                        result.first = min(result.first, k);
                        result.second = max(result.second, k);
                    }
                }

                ans[i][j - b + 1] = result.second - result.first;
            }
        }
    }

    while (k--) {
        int i, j;
        cin >> i >> j;

        cout << ans[i - 1][j - 1] << '\n';
    }

    return 0;
}

// Baekjoon09663.cpp
#include <iostream>

using namespace std;

int ans, n;
bool col[16], diag1[32], diag2[32];

void solve(int curr, int row) {
    if (curr == n)
        ans++;
    else {
        for (int i = 0; i < n; i++) {
            int idx1 = i - row + n - 1, idx2 = row + i;
            if (!col[i] && !diag1[idx1] && !diag2[idx2]) {
                col[i] = diag1[idx1] = diag2[idx2] = true;
                solve(curr + 1, row + 1);
                col[i] = diag1[idx1] = diag2[idx2] = false;
            }
        }
    }
}

int main(void) {
    cin >> n;
    
    solve(0, 0);

    cout << ans << '\n';

    return 0;
}
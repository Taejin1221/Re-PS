// Baekjoon18111.cpp
#include <iostream>

#define ABS(x) ((x) < 0 ? -(x) : (x))

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, inven;
    cin >> n >> m >> inven;

    int blocks[500][500] = { { 0, }, };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> blocks[i][j];

    pii ans = { 0x3f3f3f3, 256 };
    for (int target = 256; target >= 0; target--) {
        int second = 0, needBlock = inven;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int diff = blocks[i][j] - target;
                needBlock += diff;
                second += ABS(diff) * (diff < 0 ? 1 : 2);
            }
        }

        if (needBlock >= 0 && ans.first > second)
            ans = { second, target };
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}
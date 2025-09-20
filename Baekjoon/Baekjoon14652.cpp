// Baekjoon14652.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;

    pii ans = { 0, 0 };

    bool isFind = false;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (curr == k) {
                ans = { i, j };
                isFind = true;
                break;
            }
            curr++;
        }

        if (isFind)
            break;
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}

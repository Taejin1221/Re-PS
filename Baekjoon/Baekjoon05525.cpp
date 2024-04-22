// Baekjoon05525.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string source, target;
    cin >> target;

    for (int i = 0; i < n; i++) {
        source.push_back('I');
        source.push_back('O');
    }
    source.push_back('I');

    n = 2 * n + 1;

    int sIdx = 0, ans = 0;
    for (int tIdx = 0; tIdx < m; tIdx++) {
        if (target[tIdx] == source[sIdx]) {
            sIdx++;
            if (sIdx == n) {
                ans++;
                sIdx -= 2;
            }
        } else {
            sIdx = (target[tIdx] == 'I' ? 1 : 0);
        }
    }

    cout << ans << '\n';

    return 0;
}
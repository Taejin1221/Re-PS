// Baekjoon34722.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int boj, codeforces, atcoder, icpc;
        cin >> boj >> codeforces >> atcoder >> icpc;

        if (boj >= 1000 || codeforces >= 1600 || atcoder >= 1500 || (icpc != -1 && icpc <= 30))
            ans++;
    }

    cout << ans << '\n';

    return 0;
}

// Baekjoon31846.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        l--, r--;

        int m = (r - l) + 1;

        int ans = 0;
        for (int i = 0; i < m; i++) {
            int result = 0;
            for (int j = 0; j <= i; j++) {
                int src = r - j, target = r - (i * 2 + 1 - j);
                if (target >= l && str[src] == str[target])
                    result++;
            }
            ans = max(ans, result);
        }
        cout << ans << '\n';
    }

    return 0;
}

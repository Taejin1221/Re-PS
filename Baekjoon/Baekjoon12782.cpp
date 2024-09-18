// Baekjoon12782.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        int zero = 0, one = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (a[i] == '0')
                    zero++;
                else
                    one++;
            }
        }

        int common = min(zero, one);
        cout << common + (zero - common) + (one - common) << '\n';
    }

    return 0;
}
// Baekjoon11104.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string binary;
        cin >> binary;

        int ans = 0;
        for (int i = 0; i < binary.size(); i++) {
            ans *= 2;
            ans += binary[i] - '0';
        }

        cout << ans << '\n';
    }

    return 0;
}

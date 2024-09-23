// Baekjoon12778.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n; char prob;
        cin >> n >> prob;

        if (prob == 'C') {
            for (int i = 0; i < n; i++) {
                char a;
                cin >> a;

                cout << ((int)a - 'A') + 1 << ' ';
            }
        } else {
            for (int i = 0; i < n; i++) {
                int a;
                cin >> a;

                cout << (char)(a - 1 + 'A') << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
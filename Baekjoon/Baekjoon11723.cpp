// Baekjoon11723.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    const int all = (1 << 21) - 1;

    int t;
    cin >> t;

    int set = 0;
    while (t--) {
        string opr;
        cin >> opr;

        if (opr == "add") {
            int x;
            cin >> x;

            set |= 1 << x;
        } else if (opr == "remove") {
            int x;
            cin >> x;

            set &= (all - (1 << x));
        } else if (opr == "check") {
            int x;
            cin >> x;

            cout << ((set & (1 << x)) > 0) << '\n';
        } else if (opr == "toggle") {
            int x;
            cin >> x;

            set ^= (1 << x);
        } else if (opr == "all") {
            set = all;
        } else if (opr == "empty") {
            set = 0;
        }
    }

    return 0;
}
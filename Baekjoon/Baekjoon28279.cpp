// Baekjoon28279.cpp
#include <iostream>

#include <deque>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    deque<int> dq;
    while (t--) {
        int opr;
        cin >> opr;

        if (opr == 1) {
            int x;
            cin >> x;

            dq.push_front(x);
        } else if (opr == 2) {
            int x;
            cin >> x;

            dq.push_back(x);
        } else if (opr == 3) {
            if (dq.size()) {
                cout << dq.front();
                dq.pop_front();
            } else
                cout << -1;
            cout << '\n';
        } else if (opr == 4) {
            if (dq.size()) {
                cout << dq.back();
                dq.pop_back();
            } else
                cout << -1;
            cout << '\n';
        } else if (opr == 5) {
            cout << dq.size() << '\n';
        } else if (opr == 6) {
            cout << (dq.size() == 0) << '\n';
        } else if (opr == 7) {
            cout << (dq.size() ? dq.front() : -1) << '\n';
        } else if (opr == 8) {
            cout << (dq.size() ? dq.back() : -1) << '\n';
        }
    }

    return 0;
}
// Baekjoon05430.cpp
#include <iostream>

#include <deque>
#include <string>

using namespace std;

void solve(void) {
    string oper;
    cin >> oper;

    int n;
    cin >> n;

    string array;
    cin >> array;

    int curr = 0, idx = 0;
    deque<int> dq(n);
    for (int i = 1; i < array.size() - 1; i++) {
        if (array[i] == ',') {
            dq[idx++] = curr;
            curr = 0;
        } else {
            curr *= 10;
            curr += (int)(array[i] - '0');
        }
    }
    dq[idx] = curr;

    bool reverse = false;
    for (char& o : oper) {
        if (o == 'R')
            reverse = !reverse;
        else {
            if (dq.size() == 0) {
                cout << "error\n";
                return;
            }
            else {
                reverse ? dq.pop_back() : dq.pop_front();
            }
        }
    }

    int currN = dq.size();
    cout << '[';
    if (currN != 0) {
        if (!reverse) {
            for (int i = 0; i < currN - 1; i++)
                cout << dq[i] << ',';
            cout << dq[currN - 1];
        } else {
            for (int i = currN - 1; i > 0; i--)
                cout << dq[i] << ',';
            cout << dq[0];
        }
    }
    cout << "]\n";
   
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
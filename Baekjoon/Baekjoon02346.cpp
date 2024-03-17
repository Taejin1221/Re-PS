// Baekjoon02346.cpp
#include <iostream>

#include <deque>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    deque<pii> dq;
    for (int i = 1; i <= n; i++) {
        pii temp = { i, 0 };
        cin >> temp.second;

        dq.push_back(temp);
    }

    while (1) {
        pii curr = dq.front();
        dq.pop_front();

        cout << curr.first << ' ';
        if (dq.size() == 0)
            break;

        if (curr.second > 0) {
            for (int i = 0; i < curr.second - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            curr.second *= -1;
            for (int i = 0; i < curr.second; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << '\n';

    return 0;
}
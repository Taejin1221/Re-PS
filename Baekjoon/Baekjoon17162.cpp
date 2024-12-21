// Baekjoon17162.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q, mod;
    cin >> q >> mod;

    vector<int> stck;
    vector<int> modStck[100];
    while (q--) {
        int oper;
        cin >> oper;

        if (oper == 1) {
            int x;
            cin >> x;

            modStck[x % mod].push_back(stck.size());
            stck.push_back(x);
        } else if (oper == 2) {
            if (stck.size() == 0)
                continue;

            modStck[stck.back() % mod].pop_back();
            stck.pop_back();
        } else {
            int minIdx = stck.size() - 1;
            bool canAnswer = true;

            for (int i = 0; i < mod; i++) {
                if (modStck[i].size() == 0) {
                    canAnswer = false;
                    break;
                }

                minIdx = min(minIdx, modStck[i].back());
            }

            if (!canAnswer)
                cout << -1;
            else
                cout << stck.size() - minIdx;
            cout << '\n';
        }
    }

    return 0;
}

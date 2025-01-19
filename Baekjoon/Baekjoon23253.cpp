// Baekjoon23253.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int table[200'001];
    vector<int> stcks[200'000];
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int num;
            cin >> num;

            stcks[i].push_back(num);
            table[num] = i;
        }
    }

    bool canSort = true;
    for (int i = 1; i <= n; i++) {
        vector<int>& stck = stcks[table[i]];
        if (!(stck.size() > 0 && stck.back() == i)) {
            canSort = false;
            break;
        }

        stck.pop_back();
    }

    cout << (canSort ? "Yes" : "No") << '\n';

    return 0;
}

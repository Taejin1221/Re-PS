// Baekjoon12015.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> lis;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
        if (idx == lis.size())
            lis.push_back(num);
        else
            lis[idx] = num;
    }

    cout << lis.size() << '\n';

    return 0;
}
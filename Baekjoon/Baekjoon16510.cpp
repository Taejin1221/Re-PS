// Baekjoon16510.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> works;
    works.push_back(0);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        works.push_back(works.back() + temp);
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;

        int ans = upper_bound(works.begin(), works.end(), t) - works.begin();
        cout << ans - 1 << '\n';
    }

    return 0;
}

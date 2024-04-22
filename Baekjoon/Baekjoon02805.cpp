// Baekjoon02805.cpp
#include <iostream>

#include <vector>

using namespace std;

using ll = long long;

ll check(vector<int>& tree, ll mid) {
    ll result = 0;
    for (int& t : tree)
        result += t < mid ? 0 : t - mid;

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> tree(n);
    for (int i = 0; i < n; i++)
        cin >> tree[i];

    ll start = 0, end = 2'000'000'001;
    while (start + 1 < end) {
        ll mid = (start + end) / 2;
        (check(tree, mid) >= m) ? start = mid : end = mid;
    }

    cout << start << '\n';

    return 0;
}
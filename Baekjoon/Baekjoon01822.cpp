// Baekjoon01822.cpp
#include <iostream>

#include <set>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int a[500'000];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> b;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;

        b.insert(temp);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (b.find(a[i]) == b.end())
            ans.push_back(a[i]);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}

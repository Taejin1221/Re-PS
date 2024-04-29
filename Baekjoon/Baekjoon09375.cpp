// Baekjoon09375.cpp
#include <iostream>

#include <map>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;

    map<string, int> set;
    for (int i = 0; i < n; i++) {
        string name, sort;
        cin >> name >> sort;

        if (set.find(sort) == set.end())
            set.insert({ sort, 1 });
        else
            set.find(sort)->second++;
    }

    int ans = 1;
    for (auto iter = set.begin(); iter != set.end(); ++iter) {
        ans *= iter->second + 1;
    }

    cout << ans - 1 << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
// Baekjoon14425.cpp
#include <iostream>

#include <set>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<string> list;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        list.insert(str);
    }

    int ans = 0;
    while (m--) {
        string str;
        cin >> str;

        ans += (list.find(str) != list.end()) ? 1 : 0;
    }

    cout << ans << '\n';

    return 0;
}
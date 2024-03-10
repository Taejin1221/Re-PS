// Baekjoon01764.cpp
#include <iostream>

#include <set>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    set<string> noHear;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        noHear.insert(name);
    }

    set<string> ans;
    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;

        if (noHear.find(name) != noHear.end())
            ans.insert(name);
    }

    cout << ans.size() << '\n';
    for (auto iter = ans.begin(); iter != ans.end(); ++iter)
        cout << *iter << '\n';

    return 0;
}
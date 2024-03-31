// Baekjoon25192.cpp
#include <iostream>

#include <set>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<string> table;

    int t;
    cin >> t;

    int ans = 0;
    while (t--) {
        string str;
        cin >> str;

        if (str == "ENTER")
            table.clear();
        else {
            if (table.find(str) == table.end()) {
                ans++;
                table.insert(str);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
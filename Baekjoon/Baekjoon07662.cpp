// Baekjoon07662.cpp
#include <iostream>

#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;

    multiset<int> table;
    for (int i = 0; i < n; i++) {
        char opr; int x;
        cin >> opr >> x;
        if (opr == 'I')
            table.insert(x);
        else {
            if (table.size()) {
                if (x == -1)
                    table.erase(table.begin());
                else
                    table.erase(--(table.end()));
            }
        }
    }

    if (table.size())
        cout << *(--table.end()) << ' ' << *table.begin();
    else
        cout << "EMPTY";
    cout << '\n';

    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
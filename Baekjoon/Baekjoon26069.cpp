// Baekjoon26069.cpp
#include <iostream>

#include <set>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans = 1;
    set<string> dancing;
    dancing.insert("ChongChong");

    int t;
    cin >> t;
    while (t--) {
        string name1, name2;
        cin >> name1 >> name2;

        bool is1Dancing = (dancing.find(name1) != dancing.end()), is2Dancing = (dancing.find(name2) != dancing.end());
        if (is1Dancing && is2Dancing)
            continue;
        else if (is1Dancing) {
            ans++;
            dancing.insert(name2);
        } else if (is2Dancing) {
            ans++;
            dancing.insert(name1);
        }
    }

    cout << ans << '\n';

    return 0;
}
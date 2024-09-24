// Baekjoon32344.cpp
#include <iostream>

#include <map>
#include <algorithm>

using namespace std;

using ll = long long;
using pil = pair<int, ll>;

struct Treasure {
    int left, bottom, right, up;
    Treasure(int r, int c): left(c), bottom(r), right(c), up(r) { }

    ll getSize() {
        return (ll)(up - bottom + 1) * (right - left + 1);
    }

    void addTreasure(int row, int col) {
        left = min(left, col);
        right = max(right, col);
        bottom = min(bottom, row);
        up = max(up, row);
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int maxRow, maxCol;
    cin >> maxRow >> maxCol;

    int n;
    cin >> n;

    map<int, Treasure> treasures;
    for (int i = 0; i < n; i++) {
        int a, v, h;
        cin >> a >> v >> h;

        auto treasure = treasures.find(a);
        if (treasure == treasures.end()) {
            treasures.insert({ a, Treasure(v, h) });
        } else
            treasure->second.addTreasure(v, h);
    }

    pil ans = { 0, 0 };
    for (auto iter = treasures.begin(); iter != treasures.end(); ++iter) {
        if (iter->second.getSize() > ans.second)
            ans = { iter->first, iter->second.getSize() };
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}
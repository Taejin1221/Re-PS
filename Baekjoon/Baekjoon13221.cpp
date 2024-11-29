// Baekjoon13221.cpp
#include <iostream>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

using pii = pair<int, int>;

int main(void) {
    pii me;
    cin >> me.first >> me.second;

    int n;
    cin >> n;

    pair<pii, int> ans = { { 0, 0 }, 0x3f3f3f3f };
    for (int i = 0; i < n; i++) {
        pii taxi;
        cin >> taxi.first >> taxi.second;

        int dis = ABS(me.first - taxi.first) + ABS(me.second - taxi.second);
        if (ans.second > dis) {
            ans.first = taxi;
            ans.second = dis;
        }
    }

    cout << ans.first.first << ' ' << ans.first.second << '\n';

    return 0;
}

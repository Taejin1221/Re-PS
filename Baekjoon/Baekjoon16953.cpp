// Baekjoon16953.cpp
#include <iostream>

#include <set>
#include <queue>

using namespace std;

using ll = long long;
using pli = pair<ll, int>;

int main(void) {
    int a, b;
    cin >> a >> b;

    queue<pli> q;
    set<ll> visited;

    q.push({ a, 0 });
    visited.insert(a);

    int ans = -2;
    while (!q.empty()) {
        pli curr = q.front(); q.pop();

        if (curr.first == b) {
            ans = curr.second;
            break;
        }

        ll next[2] = { curr.first * 2, curr.first * 10 + 1 };
        for (int i = 0; i < 2; i++) {
            if (next[i] <= b && visited.find(next[i]) == visited.end()) {
                visited.insert(next[i]);
                q.push({ next[i], curr.second + 1 });
            }
        }
    }

    cout << ans + 1 << '\n';

    return 0;
}
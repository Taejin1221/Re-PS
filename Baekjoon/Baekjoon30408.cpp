// Baekjoon30408.cpp
#include <iostream>

#include <set>
#include <queue>

using namespace std;

using ll = long long;

int main(void) {
    ll n, m;
    cin >> n >> m;

    queue<ll> q;
    set<ll> visited;

    q.push(n);
    visited.insert(n);

    bool ans = false;
    while (!q.empty()) {
        ll curr = q.front(); q.pop();

        if (curr == m) {
            ans = true;
            break;
        }

        if (curr == 1)
            continue;

        ll half = curr / 2;
        if (visited.find(half) == visited.end()) {
            visited.insert(half);
            q.push(half);
        }

        if (curr % 2 == 1) {
            half++;
            if (visited.find(half) == visited.end()) {
                visited.insert(half);
                q.push(half);
            }
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
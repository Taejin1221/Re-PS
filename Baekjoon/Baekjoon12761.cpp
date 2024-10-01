// Baekjoon12761.cpp
#include <iostream>

#include <queue>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    int moves[6] = { -1, 1, -a, a, -b, b };

    queue<pii> q;
    bool visited[100'001] = { false, };

    q.push({ n, 0 });
    visited[n] = true;

    int ans;
    while (!q.empty()) {
        pii curr = q.front(); q.pop();

        if (curr.first == m) {
            ans = curr.second;
            break;
        }

        int next, nextTime = curr.second + 1;
        for (int i = 0; i < 6; i++) {
            next = curr.first + moves[i];
            if (0 <= next && next <= 100'000) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({ next, nextTime });
                }
            }
        }

        next = curr.first * a;
        if (next <= 100'000 && !visited[next]) {
            visited[next] = true;
            q.push({ next, nextTime });
        }

        next = curr.first * b;
        if (next <= 100'000 && !visited[next]) {
            visited[next] = true;
            q.push({ next, nextTime });
        }
    }

    cout << ans << '\n';

    return 0;
}
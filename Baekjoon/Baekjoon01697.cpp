// Baekjoon01697.cpp
#include <iostream>

#include <queue>
#include <vector>

#define MAX 200'000

using namespace std;

using pii = pair<int, int>;

int main(void) {
    int n, k;
    cin >> n >> k;

    queue<pii> q;
    q.push({ n, 0 });

    vector<bool> visited(MAX);
    visited[n] = true;
    
    int ans = 0x3f3f3f3f;
    while (!q.empty()) {
        pii curr = q.front(); q.pop();
        int position = curr.first, time = curr.second;
        if (position == k) {
            ans = time;
            break;
        }

        if (position + 1 < MAX && !visited[position + 1]) {
            visited[position + 1] = true;
            q.push({ position + 1, time + 1 });
        }

        if (0 <= position - 1 && !visited[position - 1]) {
            visited[position - 1] = true;
            q.push({ position - 1, time + 1 });
        }

        if (position * 2 < MAX && !visited[position * 2]) {
            visited[position * 2] = true;
            q.push({ position * 2, time + 1 });
        }
    }

    cout << ans << '\n';

    return 0;
}
// Baekjoon11060.cpp
#include <iostream>

#include <queue>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[1'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    queue<pii> q;
    bool visited[1'001] = { false, };

    q.push({ 0, 0 });
    visited[0] = true;

    int ans = -1;
    while (!q.empty()) {
        pii curr = q.front(); q.pop();

        if (curr.first == n - 1) {
            ans = curr.second;
            break;
        }

        for (int i = 1; i <= arr[curr.first]; i++) {
            int next = curr.first + i;
            if (next < n && !visited[next]) {
                visited[next] = true;
                q.push({ next, curr.second + 1 });
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
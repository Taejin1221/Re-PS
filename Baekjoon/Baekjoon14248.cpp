// Baekjoon14248.cpp
#include <iostream>

#include <queue>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[100'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int start;
    cin >> start;

    start--;

    int ans = 0;
    queue<int> q;
    bool visited[100'000] = { false, };

    q.push(start);
    visited[start] = true;
    ans++;
    while (!q.empty()) {
        int curr = q.front(); q.pop();

        int nexts[2] = { curr + arr[curr], curr - arr[curr] };
        for (int& next : nexts) {
            if (0 <= next && next < n) {
                if (!visited[next]) {
                    visited[next] = true;
                    ans++;
                    q.push(next);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

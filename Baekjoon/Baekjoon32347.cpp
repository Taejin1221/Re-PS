// Baekjoon32347.cpp
#include <iostream>

#include <queue>

using namespace std;

using pii = pair<int, int>;

int n, k;
bool isOn[200'001];

bool solve(int t) {
    queue<pii> q;
    bool visited[200'001] = { false, };

    q.push({ n, 0 });
    visited[n] = true;

    while (!q.empty()) {
        pii curr = q.front(); q.pop();
        if (curr.first == 1)
            return true;

        if (isOn[curr.first]) {
            if (curr.second == k)
                continue;

            int next = max(1, curr.first - t);

            if (!visited[next]) {
                visited[next] = true;
                q.push({ next, curr.second + 1 });
            }
        }

        int next = curr.first + 1;
        if (next <= n && !visited[next]) {
            visited[next] = true;
            q.push({ next, curr.second });
        }
    }

    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> isOn[i];

    int left = 0, right = n;
    while (left + 1 < right) {
        int mid = (left + right) / 2;

        if (solve(mid))
            right = mid;
        else
            left = mid;
    }

    cout << right << '\n';

    return 0;
}

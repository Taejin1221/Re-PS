// Baekjoon32248.cpp
#include <iostream>

#include <vector>

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, t;
    cin >> n >> t;

    int adjList[101];
    for (int i = 1; i <= n; i++)
        cin >> adjList[i];

    vector<int> stck;
    bool visited[101] = { false, };

    stck.push_back(1);

    int curr = 1, start = 0;
    while (t) {
        visited[curr] = true;

        int next = adjList[curr];
        if (!visited[next]) {
            stck.push_back(next);
            curr = next;
            t--;
        } else {
            t--;
            int cycle = 1;
            for (auto iter = stck.rbegin(); iter != stck.rend() && next != *iter; ++iter, cycle++);

            t %= cycle;
            start = next;
            break;
        }
    }

    int ans = start;
    if (ans == 0)
        ans = stck.back();
    else
        for (int i = 0; i < t; i++)
            ans = adjList[ans];

    cout << ans << '\n';

    return 0;
}

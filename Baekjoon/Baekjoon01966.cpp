// Baekjoon01966.cpp
#include <iostream>

#include <queue>

using namespace std;

using pib = pair<int, bool>;

int solve() {
    int n, target;
    cin >> n >> target;

    queue<pib> q;
    int priorityTable[10] = { 0, };
    for (int i = 0; i < n; i++) {
        int priority;
        cin >> priority;

        q.push({ priority, i == target });

        priorityTable[priority]++;
    }

    for (int ans = 0; ;) {
        pib curr = q.front(); q.pop();

        bool isPop = true;
        for (int i = curr.first + 1; i < 10; i++) {
            if (priorityTable[i]) {
                isPop = false;
                break;
            }
        }

        if (isPop) {
            priorityTable[curr.first]--;
            ans++;
            if (curr.second)
                return ans;
        } else
            q.push(curr);
    }

    return -1;
}

int main(void) {
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';

    return 0;
}
// Baekjoon16928.cpp
#include <iostream>

#include <queue>

using namespace std;

struct Node {
    int pos, time;
    Node(int p, int t): pos(p), time(t) { }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int jump[101];
    for (int i = 1; i <= 100; i++)
        jump[i] = i;

    for (int i = 0; i < n + m; i++) {
        int start, end;
        cin >> start >> end;

        jump[start] = end;
    }

    queue<Node> q;
    q.push(Node(1, 0));

    bool visited[101] = { false, true, };

    int ans;
    while (!q.empty()) {
        Node curr = q.front(); q.pop();
        if (curr.pos == 100) {
            ans = curr.time;
            break;
        }

        for (int i = 1; i <= 6; i++) {
            int nextPos = curr.pos + i;
            if (nextPos <= 100)
                nextPos = jump[curr.pos + i];

            if (nextPos <= 100 && !visited[nextPos]) {
                visited[nextPos] = true;
                q.push(Node(nextPos, curr.time + 1));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
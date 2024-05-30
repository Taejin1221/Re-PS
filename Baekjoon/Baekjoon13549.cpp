// Baekjoon13549.cpp
#include <iostream>

#include <queue>

using namespace std;

struct Node {
    int pos, time;
    Node(int p, int t): pos(p), time(t) { }
    bool operator<(const Node& n2) const {
        return time > n2.time;
    }
};

int main(void) {
    int n, k;
    cin >> n >> k;

    priority_queue<Node> pq;
    bool visited[200'001] = { false, };

    int ans = 0x3f3f3f3f;
    pq.push(Node(n, 0));
    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();
        if (curr.pos == k) {
            ans = curr.time;
            break;
        }

        if (!visited[curr.pos]) {
            visited[curr.pos] = true;

            if (curr.pos * 2 <= 200'000 && !visited[curr.pos * 2])
                pq.push(Node(curr.pos * 2, curr.time));

            if (curr.pos > 0 && !visited[curr.pos - 1])
                pq.push(Node(curr.pos - 1, curr.time + 1));

            if (curr.pos < 200'000 && !visited[curr.pos + 1])
                pq.push(Node(curr.pos + 1, curr.time + 1));
        }
    }
    
    cout << ans << '\n';

    return 0;
}
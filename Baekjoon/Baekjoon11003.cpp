// Baekjoon11003.cpp
#include <iostream>

#include <queue>

using namespace std;

struct Node {
    int val, idx;
    Node(int v, int i): val(v), idx(i) { }

    bool operator<(const Node& n2) const {
        return (val == n2.val) ? idx > n2.idx : val > n2.val;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, l;
    cin >> n >> l;

    priority_queue<Node> pq;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        pq.push(Node(num, i));

        while (pq.top().idx <= i - l)
            pq.pop();

        cout << pq.top().val << ' ';
    }
    cout << '\n';

    return 0;
}
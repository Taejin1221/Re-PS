// Baekjoon09019.cpp
#include <iostream>

#include <vector>

using namespace std;

struct Node {
    int num, preIdx;
    char alpha;

    Node(int n, char a, int p): num(n), preIdx(p), alpha(a) { }
};

int D(int a) {
    return a * 2 % 10'000;
}

int S(int a) {
    return (a ? a - 1 : 9999);
}

int L(int a) {
    return (a % 1'000) * 10 + a / 1'000;
}

int R(int a) {
    return (a % 10) * 1000 + (a / 10);
}

void solve() {
    int source, target;
    cin >> source >> target;

    int qIdx = 0;
    vector<Node> q(1, Node(source, '\0', -1));

    bool visited[10'001] = { false, };
    visited[source] = true;
    while (!q.empty()) {
        Node curr = q[qIdx];

        if (curr.num == target) {
            string ans;
            Node prev = q[qIdx];
            while (prev.preIdx != -1) {
                ans.push_back(prev.alpha);
                prev = q[prev.preIdx];
            }

            for (auto iter = ans.rbegin(); iter != ans.rend(); ++iter)
                cout << *iter;
            cout << '\n';

            break;
        }

        pair<int, char> nextInfo[4] = {
            { D(curr.num), 'D' },
            { S(curr.num), 'S' },
            { L(curr.num), 'L' },
            { R(curr.num), 'R' },
        };

        for (int i = 0; i < 4; i++) {
            int nextNum = nextInfo[i].first;
            if (!visited[nextNum]) {
                visited[nextNum] = true;

                q.push_back(Node(nextNum, nextInfo[i].second, qIdx));
            }
        }

        qIdx++;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
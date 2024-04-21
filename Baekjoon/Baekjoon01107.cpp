// Baekjoon01107.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct Node {
    int channel, time;
    bool numEnd;

    Node(int c, int t, bool ne): channel(c), time(t), numEnd(ne) { }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int target;
    cin >> target;

    int t;
    cin >> t;

    int isBreak[10] = { false, };
    for (int i = 0; i < t; i++) {
        int temp;
        cin >> temp;
        isBreak[temp] = true;
    }

    queue<Node> q;
    vector<vector<bool>> visited(2, vector<bool> (1'000'001));

    visited[0][100] = true;
    q.push(Node(100, 0, true));

    for (int i = 0; i < 10; i++) {
        if (!isBreak[i]) {
            visited[1][i] = true;
            q.push(Node(i, 1, false));
        }
    }

    int ans;
    while (!q.empty()) {
        Node curr = q.front(); q.pop();
        int channel = curr.channel, nextTime = curr.time + 1;
        if (channel == target) {
            ans = curr.time;
            break;
        }

        if (channel > 0 && !visited[0][channel - 1]) {
            visited[0][channel - 1] = true;
            q.push(Node(channel - 1, nextTime, true));
        }

        if (channel < 1'000'000 && !visited[0][channel + 1]) {
            visited[0][channel + 1] = true;
            q.push(Node(channel + 1, nextTime, true));
        }

        if (!curr.numEnd) {
            for (int i = 0; i < 10; i++) {
                if (!isBreak[i]) {
                    int next = channel * 10 + i;
                    if (next <= 1'000'000 && !visited[1][next]) {
                        visited[1][next] = true;
                        q.push(Node(next, nextTime, false));
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
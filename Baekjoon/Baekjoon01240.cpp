// Baekjoon01240.cpp
#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

vector<pii> adjList[1'001];

int getDistance(int me, int mom, int target) {
    if (me == target)
        return 0;
    else {
        for (pii& adjV : adjList[me]) {
            if (adjV.first != mom) {
                int result = getDistance(adjV.first, me, target);
                if (result != -1)
                    return result + adjV.second;
            }
        }
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        adjList[u].push_back({ v, d });
        adjList[v].push_back({ u, d });
    }

    while (m--) {
        int u, v;
        cin >> u >> v;

        cout << getDistance(u, 0, v) << '\n';
    }

    return 0;
}
// Baekjoon28106.cpp
#include <iostream>

#include <queue>
#include <vector>

#define MOD 998'244'353

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int n, jump[2'001];
ll dp[2'001];
vector<int> adjList[2'001];

int playTree(int target) {
    if (adjList[target].size() == 0)
        return 1;

    if (dp[target] == 0) {
        ll result = 0LL;

        queue<pii> q;
        if (jump[target] > 0)
            for (int& adjV : adjList[target])
                q.push({ adjV, 1 });

        while (!q.empty()) {
            pii curr = q.front(); q.pop();

            result = (result + playTree(curr.first)) % MOD;
            if (curr.second < jump[target])
                for (int& adjV : adjList[curr.first])
                    q.push({ adjV, curr.second + 1 });
        }

        dp[target] = result;
    }

    return dp[target];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int parent;
        cin >> parent;

        adjList[parent].push_back(i);
    }

    for (int i = 1; i <= n; i++)
        cin >> jump[i];

    cout << playTree(adjList[0][0]) << '\n';

    return 0;
}

// Baekjoon16168.cpp
#include <iostream>

using namespace std;

bool visited[3'001];
vector<int> adjList[3'001];

void dfs(int i) {
    visited[i] = true;
    for (int& adjV : adjList[i])
        if (!visited[adjV])
            dfs(adjV);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(1);

    bool seperate = false;
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            seperate = true;
            break;
        }
    }

    if (seperate)
        cout << "NO";
    else {
        int odd = 0;
        for (int i = 1; i <= v; i++)
            if (adjList[i].size() % 2 == 1)
                odd++;

        cout << ((odd == 0 || odd == 2) ? "YES" : "NO");
    }
    cout << '\n';

    return 0;
}

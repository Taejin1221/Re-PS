// Baekjoon01043.cpp
#include <iostream>

#include <vector>

using namespace std;

bool truthKnower[51], visited[51];
vector<int> adjList[51];

void dfs(int curr) {
    for (int& adj : adjList[curr]) {
        if (!visited[adj]) {
            visited[adj] = true;
            truthKnower[adj] = true;
            dfs(adj);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int knowerNum;
    cin >> knowerNum;

    for (int i = 0; i < knowerNum; i++) {
        int knower;
        cin >> knower;

        truthKnower[knower] = true;
    }

    
    vector<int> parties[51];
    for (int i = 0; i < m; i++) {
        int peopleNum;
        cin >> peopleNum;

        int prev;
        cin >> prev;
        parties[i].push_back(prev);

        for (int j = 1; j < peopleNum; j++) {
            int curr;
            cin >> curr;
            parties[i].push_back(curr);

            adjList[prev].push_back(curr);
            adjList[curr].push_back(prev);
        }
    }

    
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && truthKnower[i]) {
            visited[i] = true;
            dfs(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        bool isTruth = false;
        for (int& person : parties[i]) {
            if (truthKnower[person]) {
                isTruth = true;
                break;
            }
        }

        ans += (isTruth ? 0 : 1);
    }

    cout << ans << '\n';

    return 0;
}
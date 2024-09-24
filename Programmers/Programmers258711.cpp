// Programmers258711.cpp
#include <vector>

using namespace std;

bool visited[1'000'001] = { false, };
vector<int> adjList[1'000'001];

void dfs(int curr) {
    if (adjList[curr].size() != 0) {
        int next = adjList[curr][0];
        if (!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> ans(4);

    int n = 0;
    bool isNode[1'000'001] = { false, };
    int indegree[1'000'001] = { 0, }, outdegree[1'000'001] = { 0, };
    for (vector<int>& edge : edges) {
        n = max(n, max(edge[0], edge[1]));
        isNode[edge[0]] = true;
        isNode[edge[1]] = true;

        adjList[edge[0]].push_back(edge[1]);
        outdegree[edge[0]]++;
        indegree[edge[1]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0 && outdegree[i] >= 2) {
            ans[0] = i;
            for (int& adj : adjList[i])
                indegree[adj]--;
            break;
        }
    }

    vector<int> stick; // indegree가 0개이고 outdegree가 1개 이하인 노드들
    vector<int> graph8; // outdegree가 2개인 노드들
    for (int i = 1; i <= n; i++) {
        if (isNode[i] && indegree[i] == 0 && outdegree[i] <= 1)
            stick.push_back(i);
        else if (indegree[i] == 2 && outdegree[i] == 2)
            graph8.push_back(i);
    }

    for (int& i : stick) {
        visited[i] = true;
        dfs(i);
        ans[2]++;
    }

    for (int& i : graph8) {
        visited[i] = true;
        visited[adjList[i][0]] = true;
        visited[adjList[i][1]] = true;

        dfs(adjList[i][0]);
        dfs(adjList[i][1]);

        ans[3]++;
    }

    visited[ans[0]] = true;
    for (int i = 1; i <= n; i++) {
        if (isNode[i] && !visited[i]) {
            visited[i] = true;
            dfs(i);
            ans[1]++;
        }
    }

    return ans;
}
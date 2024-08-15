// Baekjoon02623.cpp
#include <iostream>

#include <vector>
#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int indegree[1'001] = { 0, };
	vector<int> adjList[1'001];
	for (int i = 0; i < m; i++) {
		int order;
		cin >> order;

		int prev;
		cin >> prev;
		for (int i = 1; i < order; i++) {
			int curr;
			cin >> curr;

			adjList[prev].push_back(curr);
			indegree[curr]++;

			prev = curr;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!indegree[i])
			q.push(i);

	vector<int> ans;
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		ans.push_back(curr);

		for (int& adj : adjList[curr])
			if (--indegree[adj] == 0)
				q.push(adj);
	}

	if (ans.size() != n)
		cout << 0 << '\n';
	else
		for (int& a : ans)
			cout << a << '\n';

	return 0;
}
// Baekjoon01821.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

int n, f;

bool solve(vector<int>& nums, bool visited[]) {
	if (nums.size() == n) {
		queue<int> q;
		for (int i = 0; i < nums.size(); i++)
			q.push(nums[i]);

		while (q.size() > 1) {
			int prevSize = q.size();
			for (int i = 0; i < prevSize - 1; i++) {
				int front = q.front(); q.pop();
				q.push(front + q.front());
			}
			q.pop();
		}

		if (q.front() == f)
			return true;
		else
			return false;
	} else {
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				nums.push_back(i);
				if (solve(nums, visited))
					return true;
				nums.pop_back();
				visited[i] = false;
			}
		}

		return false;
	}
}

int main(void) {
	cin >> n >> f;

	bool visited[11] = { false, };
	vector<int> ans;

	solve(ans, visited);

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}

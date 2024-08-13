// Baekjoon02098.cpp
#include <iostream>

#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int n;
int adjMat[16][16], dp[16][16][65'536];

int solve(int start, int end, int visited) {
	int& result = dp[start][end][visited];
	if (result == -1) {
		result = INF;
		if ((visited & (1 << start)) && (visited & (1 << end)))
			for (int i = 0; i < n; i++)
				if (visited & (1 << i))
					result = min(result, solve(start, i, visited ^ (1 << end)) + adjMat[i][end]);
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fill(dp[i][j], dp[i][j] + (1 << n), -1);

			cin >> adjMat[i][j];

			if (adjMat[i][j] == 0)
				adjMat[i][j] = INF;
		}
	}

	for (int i = 0; i < n; i++) {
		dp[i][i][1 << i] = 0;
	}

	int ans = INF, allVisit = (1 << n) - 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans = min(ans, solve(i, j, allVisit) + adjMat[j][i]);

	cout << ans << '\n';

	return 0;
}
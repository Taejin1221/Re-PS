// Baekjoon01495.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, s, m;
	cin >> n >> s >> m;

	int songs[50];
	for (int i = 0; i < n; i++)
		cin >> songs[i];

	bool dp[51][1'001] = { { false, } };
	dp[0][s] = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i][j]) {
				if (j - songs[i] >= 0)
					dp[i + 1][j - songs[i]] = true;

				if (j + songs[i] <= m)
					dp[i + 1][j + songs[i]] = true;
			}
		}
	}

	int i;
	for (i = m; i >= 0 && dp[n][i] == false; i--);

	if (i == 0 && dp[n][i] == false)
		cout << -1;
	else
		cout << i;
	cout << '\n';

	return 0;
}
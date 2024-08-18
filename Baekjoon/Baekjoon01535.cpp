// Baekjoon01535.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int hp[20];
	for (int i = 0; i < n; i++)
		cin >> hp[i];

	int happy[20];
	for (int i = 0; i < n; i++)
		cin >> happy[i];

	int dp[100] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 99; j >= 0; j--)
			if (dp[j] && j + hp[i] < 100)
				dp[j + hp[i]] = max(dp[j + hp[i]], dp[j] + happy[i]);
		dp[hp[i]] = max(dp[hp[i]], happy[i]);
	}

	int ans = 0;
	for (int i = 0; i < 100; i++)
		ans = max(ans, dp[i]);
	cout << ans << '\n';

	return 0;
}
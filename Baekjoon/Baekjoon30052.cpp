// Baekjoon30052.cpp
#include <iostream>

#define ABS(x) (((x) < 0) ? (-(x)) : (x))

using namespace std;

int getTaxiDistance(int r1, int c1, int r2, int c2) {
	return ABS(r1 - r2) + ABS(c1 - c2);
}

int main(void) {
	int n ,m;
	cin >> n >> m;

	int d;
	cin >> d;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int maxDistance = max(
				max(getTaxiDistance(i, j, 0, 0), getTaxiDistance(i, j, 0, m - 1)),
				max(getTaxiDistance(i, j, n - 1, 0), getTaxiDistance(i, j, n - 1, m - 1))
			);
			if (maxDistance < d)
				ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
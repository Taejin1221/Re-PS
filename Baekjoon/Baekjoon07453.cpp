// Baekjoon07453.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int arr[4][4'000];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[j][i];

	int idx = 0;
	vector<int> twoSum(n * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = arr[0][i] + arr[1][j];

			twoSum[idx++] = sum;
		}
	}
	sort(twoSum.begin(), twoSum.end());

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = arr[2][i] + arr[3][j];

			ans += upper_bound(twoSum.begin(), twoSum.end(), -sum) - lower_bound(twoSum.begin(), twoSum.end(), -sum);
		}
	}

	cout << ans << '\n';

	return 0;
}
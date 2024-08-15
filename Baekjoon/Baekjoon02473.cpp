// Baekjoon02473.cpp
#include <iostream>

#include <algorithm>

#define INF 3'000'000'000LL
#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

using ll = long long;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll arr[5'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	ll ansVal = INF;
	int ans[3] = { 0, 0, 0 };
	for (int i = 0; i < n - 2; i++) {
		int left = i + 1, right = n - 1;
		while (left < right) {
			ll curr = ABS(arr[i] + arr[left] + arr[right]);
			if (ansVal > curr) {
				ansVal = curr;
				ans[0] = arr[i], ans[1] = arr[left], ans[2] = arr[right];
			}

			if (arr[i] + arr[left] + arr[right] < 0)
				left++;
			else
				right--;
		}
	}

	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';

	return 0;
}
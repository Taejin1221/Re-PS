// Baekjoon02491.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int arr[100'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = 1, len = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] <= arr[i])
			len++;
		else
			len = 1;

		ans = max(ans, len);
	}

	len = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] >= arr[i])
			len++;
		else
			len = 1;

		ans = max(ans, len);
	}

	cout << ans << '\n';

	return 0;
}
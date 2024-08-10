// Baekjoon02776.cpp
#include <iostream>

#include <set>

using namespace std;

void solve() {
	int n;
	cin >> n;

	set<int> arr;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		arr.insert(num);
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		cout << (arr.find(num) == arr.end() ? 0 : 1) << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
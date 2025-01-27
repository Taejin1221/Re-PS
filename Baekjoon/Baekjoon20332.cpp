// Baekjoon20332.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		sum += num;
	}

	cout << (sum % 3 == 0 ? "yes" : "no") << '\n';

	return 0;
}

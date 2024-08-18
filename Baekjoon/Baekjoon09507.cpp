// Baekjoon09507.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long fib[68] = { 1, 1, 2, 4, };
	for (int i = 4; i <= 67; i++)
		fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3] + fib[i - 4];

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		cout << fib[n] << '\n';
	}

	return 0;
}
// Baekjoon23977.cpp
#include <iostream>

using namespace std;

using ll = long long;

ll getGCD(ll a, ll b) {
	return b ? getGCD(b, a % b) : a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k, n;
	cin >> k >> n;

	int arr[8];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	ll lcm = arr[0];
	for (int i = 1; i < n; i++) {
		ll gcd = arr[i] < lcm ? getGCD(lcm, arr[i]) : getGCD(arr[i], lcm);
		lcm = lcm * arr[i] / gcd;
	}
	cout << lcm - k << '\n';

	return 0;
}
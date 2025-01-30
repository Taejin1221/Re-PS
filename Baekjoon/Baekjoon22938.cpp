// Baekjoon22938.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
	ll x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	ll xDiff = (x1 - x2) * (x1 - x2), yDiff = (y1 - y2) * (y1 - y2);
	ll rad = (r1 + r2);

	if (xDiff + yDiff < rad * rad)
		cout << "YES";
	else
		cout << "NO";
	cout << '\n';

	return 0;
}

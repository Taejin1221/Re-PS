// Baekjoon09656.cpp
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	bool isWin[1'001];
	isWin[1] = false;
	isWin[2] = true;
	isWin[3] = false;

	for (int i = 4; i <= n; i++) {
		if (isWin[i - 1] && isWin[i - 3])
			isWin[i] = false;
		else
			isWin[i] = true;
	}

	cout << (isWin[n] ? "SK" : "CY") << '\n';

	return 0;
}
// Baekjoon32132.cpp
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	char str[51];
	cin >> str;

	bool deleted[50] = { false, };
	for (int i = 0; i < n - 1; i++) {
		if (str[i] == 'P' && str[i + 1] == 'S') {
			int currI = i + 2;
			while (currI < n && (str[currI] == '4' || str[currI] == '5')) {
				deleted[currI] = true;
				currI++;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (!deleted[i])
			cout << str[i];
	cout << '\n';

	return 0;
}
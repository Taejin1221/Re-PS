// Baekjoon17388.cpp
#include <iostream>

using namespace std;

int main(void) {
	int s, k, h;
	cin >> s >> k >> h;

	if (s + k + h >= 100)
		cout << "OK";
	else {
		if (s < k && s < h)
			cout << "Soongsil";
		else if (k < s && k < h)
			cout << "Korea";
		else if (h < s && h < k)
			cout << "Hanyang";
	}
	cout << '\n';

	return 0;
}

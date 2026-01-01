// Baekjoon26264.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	string str;
	cin >> str;

	n = str.size();

	int b = 0, s = 0;

	int i = 0;
	while (i < n) {
		if (str[i] == 'b') {
			b++;
			i += 7;
		} else {
			s++;
			i += 8;
		}
	}

	if (b > s)
		cout << "bigdata?";
	else if (s > b)
		cout << "security!";
	else
		cout << "bigdata? security!";
	cout << '\n';

	return 0;
}

// Baekjoon31430.cpp
#include <iostream>

#include <string>

using namespace std;

using ll = long long;

string convertToString(ll a) {
	string str;

	while (a) {
		str.push_back((char)(a % 26) + 'a');
		a /= 26;
	}

	string result;
	for (int i = 0; i < 13 - str.size(); i++)
		result.push_back('a');

	for (auto iter = str.rbegin(); iter != str.rend(); ++iter)
		result.push_back(*iter);

	return result;
}

ll convertToNumber(string a) {
	ll exp = 1, result = 0;
	for (auto iter = a.rbegin(); iter != a.rend(); ++iter) {
		result += (int)(*iter - 'a') * exp;
		exp *= 26;
	}

	return result;
}

int main(void) {
	int t;
	cin >> t;

	if (t == 1) {
		ll a, b;
		cin >> a >> b;

		cout << convertToString(a + b) << '\n';
	} else {
		string str;
		cin >> str;

		cout << convertToNumber(str) << '\n';
	}

	return 0;
}
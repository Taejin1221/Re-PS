// Baekjoon11005.cpp
#include <iostream>

#include <string>

using namespace std;

char itoc(int i) {
    return (i < 10) ? (char)i + '0' : (char)(i - 10) + 'A';
}

int main(void) {
    int n, b;
    cin >> n >> b;

    string ans = "";
    while (n) {
        ans.push_back(itoc(n % b));
        n /= b;
    }

    for (auto iter = ans.rbegin(); iter != ans.rend(); iter++)
        cout << *iter;
    cout << '\n';

    return 0;
}
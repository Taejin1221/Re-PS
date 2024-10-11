// Baekjoon16499.cpp
#include <iostream>

#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set<string> dict;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        sort(str.begin(), str.end());
        dict.insert(str);
    }

    cout << dict.size() << '\n';

    return 0;
}
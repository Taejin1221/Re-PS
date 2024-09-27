// Baekjoon26122.cpp
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<int> magnetic;

    char prev = str[0];
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (prev == str[i])
            len++;
        else {
            magnetic.push_back(len);
            prev = str[i];
            len = 1;
        }
    }
    magnetic.push_back(len);

    int ans = 0;
    for (int i = 0; i < magnetic.size() - 1; i++) {
        ans = max(ans, min(magnetic[i], magnetic[i + 1]) * 2);
    }

    cout << ans << '\n';
}
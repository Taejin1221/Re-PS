// Baekjoon03986.cpp
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        vector<char> stck;
        for (char& c : str) {
            if (stck.empty() || stck.back() != c)
                stck.push_back(c);
            else
                stck.pop_back();
        }

        ans += stck.empty();
    }

    cout << ans << '\n';

    return 0;
}
// Baekjoon02195.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string s, p;
    cin >> s >> p;

    int n = s.size(), m = p.size();

    int pStart = 0, ans = 0;
    while (pStart < m) {
        int maxLen = 0;
        for (int sStart = 0; sStart < n; sStart++) {
            int tempLen = 0;
            for (int i = 0; (sStart + i) < n && (pStart + i) < m && s[sStart + i] == p[pStart + i]; i++)
                tempLen++;
            maxLen = max(maxLen, tempLen);
        }

        ans++;
        pStart += maxLen;
    }

    cout << ans << '\n';

    return 0;
}

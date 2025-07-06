#include <iostream>

#include <string>

using namespace std;

int get_diff(string& s1, string& s2, int start, int n) {
    int result = 0;
    for (int i = 0; i < n; i++)
        result += (s1[i] != s2[start + i]);

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size(), m = str2.size();

    int ans = 100;
    for (int i = 0; i <= m - n; i++) {
        ans = min(ans, get_diff(str1, str2, i, n));
    }

    cout << ans << '\n';

    return 0;
}

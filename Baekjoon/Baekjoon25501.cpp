// Baekjoon25501.cpp
#include <iostream>

#include <string>

using namespace std;

int result;

int recursion(string& str, int l, int r) {
    result++;
    if (l >= r)
        return 1;
    else if (str[l] != str[r])
        return 0;
    else
        return recursion(str, l + 1, r - 1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        result = 0;
        cout << recursion(str, 0, str.size() - 1) << ' ' << result << '\n';
    }

    return 0;
}
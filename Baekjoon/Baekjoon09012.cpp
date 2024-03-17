// Baekjoon09012.cpp
#include <iostream>

#include <string>

#define YES "YES"
#define NO "NO"

using namespace std;

string isVPS(string& str) {
    int open = 0;
    for (char& s : str) {
        if (s == '(')
            open++;
        else {
            if (open == 0)
                return NO;
            else
                open--;
        }
    }

    return open ? NO : YES;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        cout << isVPS(str) << '\n';
    }

    return 0;
}
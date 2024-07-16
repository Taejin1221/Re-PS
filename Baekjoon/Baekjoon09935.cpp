// Baekjoon09935.cpp
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string str, explo;
    cin >> str >> explo;

    int n = str.size(), m = explo.size();

    vector<char> newStr;
    for (int i = 0; i < n; i++) {
        newStr.push_back(str[i]);

        if (newStr.size() >= m) {
            bool isSubstr = true;

            int newN = newStr.size();
            for (int i = 1; i <= m; i++) {
                if (newStr[newN - i] != explo[m - i]) {
                    isSubstr = false;
                    break;
                }
            }

            if (isSubstr)
                for (int i = 0; i < m; i++)
                    newStr.pop_back();
        }
    }

    if (newStr.size() == 0)
        cout << "FRULA";
    else
        for (char& c : newStr)
            cout << c;
    cout << '\n';

    return 0;
}
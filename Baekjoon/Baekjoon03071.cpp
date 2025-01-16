// Baekjoon03071.cpp
#include <iostream>

#include <vector>
#include <string>

using namespace std;

string convert(int a) {
    string tri = "";
    while (a) {
        tri.push_back(a % 3);
        a /= 3;
    }

    string result = "";
    for (int i = 0; i < tri.size(); i++) {
        if (tri[i] == 2) {
            if (result.size() == i + 1) {
                if (result[i] == '0')
                    result[i] = '-';
                else if (result[i] == '1')
                    result[i] = '0';
                result.push_back('1');
            } else {
                result.push_back('-');
                result.push_back('1');
            }
        } else if (tri[i] == 1) {
            if (result.size() == i + 1) {
                if (result[i] == '0')
                    result[i] = '1';
                else if (result[i] == '1') {
                    result[i] = '-';
                    result.push_back('1');
                }
            } else
                result.push_back(tri[i] + '0');
        } else {
            if (result.size() < i + 1)
                result.push_back(tri[i] + '0');
        }
    }

    string ans = "";
    for (auto iter = result.rbegin(); iter != result.rend(); ++iter)
        ans.push_back(*iter);

    return ans;
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string ans;
        if (n > 0)
            cout << convert(n);
        else if (n == 0)
            cout << 0;
        else {
            string ans = convert(-n);

            for (int i = 0; i < ans.size(); i++) {
                if (ans[i] == '1')
                    cout << '-';
                else if (ans[i] == '-')
                    cout << '1';
                else
                    cout << '0';
            }
        }
        cout << '\n';
    }

    return 0;
}

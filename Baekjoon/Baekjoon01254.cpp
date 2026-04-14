// Baekjoon01254.cpp
#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string& str) {
    for (int left = 0, right = (int)str.size() - 1; left < right; left++, right--)
        if (str[left] != str[right])
            return false;

    return true;
}

int main(void) {
    string str;
    cin >> str;

    int n = (int)str.size();

    string temp = str;
    vector<char> stck;
    int ans = n, idx = 0;
    while (idx < n && !isPalindrome(temp)) {
        stck.push_back(str[idx++]);

        temp = str;
        for (auto iter = stck.rbegin(); iter != stck.rend(); ++iter)
            temp.push_back(*iter);
        ans = (int)temp.size();
    }

    cout << ans << '\n';

    return 0;
}

// Baekjoon17609.cpp
#include <iostream>

#include <string>

using namespace std;

bool isPalindrome(string& str, int left, int right) {
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++, right--;
    }

    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;

        int ans = 0;
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) {
                if (isPalindrome(str, left + 1, right) || isPalindrome(str, left, right - 1)) {
                    ans = 1;
                    break;
                } else {
                    ans = 2;
                    break;
                }
            } else
                left++, right--;
        }

        cout << ans << '\n';
    }
}
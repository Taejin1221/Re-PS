// Baekjoon11068.cpp
#include <iostream>

#include <vector>

using namespace std;

bool isPalindrome(int num, int base) {
    vector<int> stck;

    while (num) {
        stck.push_back(num % base);
        num /= base;
    }

    int n = stck.size();
    for (int i = 0; i < n / 2; i++)
        if (stck[i] != stck[n - i - 1])
            return false;

    return true;
}

void solve() {
    int n;
    cin >> n;

    bool can = false;
    for (int i = 2; i <= 64; i++) {
        if (isPalindrome(n, i)) {
            can = true;
            break;
        }
    }

    cout << (can ? 1 : 0) << '\n';
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

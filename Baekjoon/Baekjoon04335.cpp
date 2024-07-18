// Baekjoon04335.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    bool isStanHonest = true;
    int left = 1, right = 10;
    while (n != 0) {
        string str1, str2;
        cin >> str1 >> str2;

        if (str1 == "right") {
            if (!(left <= n && n <= right))
                isStanHonest = false;

            cout << "Stan " << (isStanHonest ? "may be honest" : "is dishonest") << '\n';

            isStanHonest = true;
            left = 1, right = 10;
        } else {
            if (str2 == "high") {
                if (n <= left)
                    isStanHonest = false;
                else
                    right = min(n - 1, right);
            } else {
                if (right <= n)
                    isStanHonest = false;
                else
                    left = max(left, n + 1);
            }
        }

        cin >> n;
    }

    return 0;
}
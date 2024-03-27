// Baekjoon01874.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    char str[1'000'000] = { 0, };
    int strIdx = 0, stck[100'000], stckIdx = 0;

    bool ans = true;
    int t, n = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int curr;
        cin >> curr;

        while (curr >= n) {
            stck[stckIdx++] = n;
            str[strIdx++] = '+';
            n++;
        }

        if (curr == stck[stckIdx - 1]) {
            stckIdx--;
            str[strIdx++] = '-';
        } else
            ans = false;
    }

    if (!ans)
        cout << "NO" << '\n';
    else {
        for (int i = 0; i < strIdx; i++)
            cout << str[i] << '\n';
    }

    return 0;    
}
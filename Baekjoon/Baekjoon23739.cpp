// Baekjoon23739.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int chapter[100];
    for (int i = 0; i < n; i++)
        cin >> chapter[i];

    int ans = 0, i = 0;
    while (i < n) {
        int remain = 30;
        while (i < n && remain > 0) {
            if ((chapter[i] + 1) / 2 <= remain)
                ans++;
            remain -= chapter[i];
            i++;
        }
    }

    cout << ans << '\n';

    return 0;
}
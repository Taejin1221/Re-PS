// Baekjoon02501.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    int n, k;
    cin >> n >> k;

    pii ans = { 1, 0 };
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (ans.first == k) {
                ans.second = i;
                break;
            } else
                ans.first++;
        }
    }

    cout << ans.second << '\n';

    return 0;
}
// Baekjoon23795.cpp
#include <iostream>

using namespace std;

int main(void) {
    int ans = 0;

    int n;
    cin >> n;
    while (n != -1) {
        ans += n;
        cin >> n;
    }

    cout << ans << '\n';

    return 0;
}

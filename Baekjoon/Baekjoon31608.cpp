// Baekjoon31608.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
                ans++;
    }

    cout << ans << '\n';

    return 0;
}

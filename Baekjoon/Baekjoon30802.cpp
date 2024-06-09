// Baekjoon30802.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int tSize[6];
    for (int i = 0; i < 6; i++)
        cin >> tSize[i];

    int t, p;
    cin >> t >> p;

    int ans = 0;
    for (int i = 0; i < 6; i++)
        ans += tSize[i] / t + ((tSize[i] % t) > 0 ? 1 : 0);
    
    cout << ans << '\n';
    cout << n / p << ' ' << n % p << '\n';

    return 0;
}
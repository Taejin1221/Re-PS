// Baekjoon11047.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int ans = 0;
    for (auto iter = coins.rbegin(); iter != coins.rend(); ++iter) {
        ans += k / *iter;
        k %= *iter;
    }

    cout << ans << '\n';

    return 0;
}
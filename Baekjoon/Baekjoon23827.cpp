// Baekjoon23827.cpp
#include <iostream>

#include <vector>

#define MOD 1'000'000'007

using namespace std;

using ll = long long;

int main(void) {
    int n;
    cin >> n;

    vector<int> arr(n);
    ll sum = 0LL;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum = sum + arr[i];
    }
    
    ll ans = 0LL;
    for (int i = 0; i < n; i++) {
        sum -= arr[i];
        ans = (ans + ((arr[i] * sum) % MOD)) % MOD;
    }

    cout << ans << '\n';

    return 0;
}
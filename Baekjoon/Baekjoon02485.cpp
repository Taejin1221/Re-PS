// Baekjoon02485.cpp
#include <iostream>

#include <vector>

using namespace std;

int getGCD(int a, int b) {
    return (a % b) ? getGCD(b, a % b) : b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    cin >> arr[0];

    vector<int> diff(n - 1);
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        diff[i - 1] = arr[i] - arr[i - 1];
    }

    int gcd = diff[0];
    for (int i = 1; i < n - 1; i++)
        gcd = gcd < diff[i] ? getGCD(diff[i], gcd) : getGCD(gcd, diff[i]);

    int ans = 0;
    for (int& d : diff)
        ans += d / gcd - 1;

    cout << ans << '\n';

    return 0;
}
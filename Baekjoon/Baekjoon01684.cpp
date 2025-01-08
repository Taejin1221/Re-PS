// Baekjoon01684.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int getGCD(int a, int b) {
    return b ? getGCD(b, a % b) : a;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[1'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int gcd = n > 1 ? arr[1] - arr[0] : arr[0];
    for (int i = 2; i < n; i++) {
        int diff = arr[i] - arr[i - 1];
        if (diff != 0)
            gcd = gcd < diff ? getGCD(diff, gcd) : getGCD(gcd, diff);
    }

    cout << gcd << '\n';

    return 0;
}

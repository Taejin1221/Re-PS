// Baekjoon26090.cpp
#include <iostream>

#include <algorithm>

#define MAX 1'000'001

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    bool isPrime[MAX];
    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < MAX; i++) {
        if (isPrime[i]) {
            for (int j = i; i * j < MAX; j++) {
                isPrime[i * j] = false;
            }
        }
    }

    int n;
    cin >> n;

    int arr[2'000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;
    for (int len = 1; len <= n; len++) {
        if (isPrime[len]) {
            for (int i = 0; i <= n - len; i++) {
                int sum = 0;
                for (int k = 0; k < len; k++)
                    sum += arr[i + k];
                if (isPrime[sum])
                    ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
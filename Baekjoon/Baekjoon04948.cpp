// Baekjoon04948.cpp
#include <iostream>

#include <algorithm>

// 123'456 * 2 + 1
#define MAX 246'913

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    bool isPrime[MAX] = { false, };
    fill(isPrime + 2, isPrime + MAX, true);

    for (int i = 2; i * i < MAX; i++)
        if (isPrime[i])
            for (int j = i * i; j < MAX; j += i)
                isPrime[j] = false;

    int n;
    cin >> n;
    while (n) {
        int ans = 0;
        for (int i = n + 1; i <= 2 * n; i++)
            ans += (isPrime[i] ? 1 : 0);
        cout << ans << '\n';

        cin >> n;
    }
}
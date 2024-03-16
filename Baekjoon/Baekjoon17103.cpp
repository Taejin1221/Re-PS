// Baekjoon17103.cpp
#include <iostream>

#include <vector>
#include <algorithm>

#define MAX 1'000'001

using namespace std;

int main(void) {
    // Fill sieve of Eratosthenes
    bool isPrime[MAX] = { false, };
    fill(isPrime + 2, isPrime + MAX, true);

    for (int i = 2; i * i < MAX; i++)
        if (isPrime[i])
            for (int j = i * i; j < MAX; j += i)
                isPrime[j] = false;

    vector<int> primeNumbers;
    for (int i = 2; i < MAX; i++)
        if (isPrime[i])
            primeNumbers.push_back(i);

    // Solve problem
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int ans = 0;
        for (int i = 0; primeNumbers[i] <= n / 2; i++)
            if (isPrime[n - primeNumbers[i]])
                ans++;

        cout << ans << '\n';
    }

    return 0;
}
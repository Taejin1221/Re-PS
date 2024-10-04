// Baekjoon01644.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    bool isPrime[4'000'001];
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= 4'000'000; i++)
        if (isPrime[i])
            for (int j = i * i; j <= 4'000'000; j += i)
                isPrime[j] = false;

    vector<int> primes;
    for (int i = 2; i <= 4'000'000; i++)
        if (isPrime[i])
            primes.push_back(i);

    int left = 0, sum = 0, ans = 0;
    for (int right = 0; right < primes.size(); right++) {
        sum += primes[right];
        while (left < right && sum > n) {
            sum -= primes[left];
            left++;
        }

        if (sum == n)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
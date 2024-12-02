// Baekjoon16894.cpp
#include <iostream>

#include <vector>
#include <iostream>

using namespace std;

using ll = long long;

vector<int> primes;
bool primeTable[4'000'000];

ll min(ll a, ll b) { return (a < b ? a : b); }

bool isPrime(ll n) {
    if (n < 4'000'000) {
        if (primeTable[n])
            return true;
        else
            return false;    
    } else {
        // sqrt(10^13)보다 n이 크다면 소수로 나눠보며 판단
        for (int& prime : primes)
            if (n % prime == 0)
                return false;

        return true;
    }
}

int main(void) {
    ll n;
    cin >> n;

    fill(primeTable, primeTable + 4'000'000, true);

    // 대충 sqrt(10^13)정도까지 소수 여부 판단
    primeTable[0] = primeTable[1] = false;
    for (ll i = 2; i < 4'000'000; i++) {
        if (primeTable[i]) {
            primes.push_back(i);
            for (ll j = i * i; j < min(n, 4'000'000); j += i)
                primeTable[j] = false;
        }
    }

    bool isKoo = true;
    for (ll i = 2; i < min(n, 4'000'000LL); i++) {
        // n이 소수로 나눠진다면
        if (isPrime(i) && (n % i == 0)) {
            // n이 소수 2개로만 이루어진 수라면
            if (isPrime(n / i))
                isKoo = false;
            // n이 소수거나 2개 초과로 이루어진 수라면
            else
                isKoo = true;
        }
    }

    cout << (isKoo ? "koosaga" : "cubelover") << '\n';

    return 0;
}

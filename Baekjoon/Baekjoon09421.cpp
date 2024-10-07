// Baekjoon09421.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

// 0: not visited, 1: visited 2: not sanggeun, 3: sanggeun
int visited[1'000'001] = { 0, };

bool isSanggeun(int prime) {
    visited[prime] = 1;
    vector<int> stck(1, prime);
    while (prime != 1 && visited[prime] != 3) {
        int temp = prime;
        prime = 0;
        while (temp) {
            prime += (temp % 10) * (temp % 10);
            temp /= 10;
        }

        if (visited[prime] == 1 || visited[prime] == 2) {
            visited[prime] = 2;
            while (!stck.empty()) {
                visited[stck.back()] = 2;
                stck.pop_back();
            }

            return false;
        } else if (visited[prime] == 0)  {
            visited[prime] = 1;
            stck.push_back(prime);
        }
    }

    visited[prime] = 3;
    while (!stck.empty()) {
        visited[stck.back()] = 3;
        stck.pop_back();
    }

    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    int n;
    cin >> n;

    bool isPrime[1'000'001];
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;

    vector<int> primes;
    for (ll i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= n; j += i)
                isPrime[j] = false;

            primes.push_back(i);
        }
    }

    for (int prime : primes) {
        if (isSanggeun(prime))
            cout << prime << '\n';
    }

    return 0;
}
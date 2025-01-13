// Baekjoon09527.cpp
#include <iostream>

using namespace std;

using ll = long long;

ll getSum(ll target, ll x) {
    ll half = x / 2;
    if (target < half)
        return 0LL;
    
    ll remain = target % x;
    if (remain >= half)
        return target / x * half + (remain - half + 1);
    else
        return getSum(target - remain - 1, x);
}

int main(void) {
    ll a, b;
    cin >> a >> b;

    ll sumA = 0LL, sumB = 0LL;
    for (int i = 1; i <= 55; i++) {
        sumA += getSum(a - 1, (1LL << i));
        sumB += getSum(b, (1LL << i));
    }

    cout << sumB - sumA << '\n';

    return 0;
}

// Baekjoon15829.cpp
#include <iostream>

#include <string>

#define R 31
#define MOD 1'234'567'891

using namespace std;

using ll = long long;

ll rPower(int exp) {
    ll result = 1;
    for (int i = 0; i < exp; i++)
        result = result * R % MOD;

    return result;
}


int main(void) {
    int l;
    cin >> l;

    string str;
    cin >> str;

    ll result = 0LL;
    for (int i = 0; i < l; i++)
        result = (result + ((ll)(str[i] - 'a' + 1) * rPower(i) % MOD)) % MOD;
    cout << result << '\n';

    return 0;
}
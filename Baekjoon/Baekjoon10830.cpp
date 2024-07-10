// Baekjoon10830.cpp
#include <iostream>

#define MOD 1'000LL

using namespace std;

using ll = long long;

struct Matrix {
    ll n;
    ll arr[5][5];

    Matrix(ll n) {
        this->n = n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = 0LL;
    }
};

Matrix product(Matrix a, Matrix b) {
    ll n = a.n;
    Matrix result(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++)
                sum = (sum + a.arr[i][k] * b.arr[k][j]) % MOD;
            result.arr[i][j] = sum;
        }
    }

    return result;
}

Matrix power(Matrix& a, ll exp) {
    if (exp == 1)
        return a;
    else {
        Matrix half = power(a, exp / 2);

        Matrix result = product(half, half);
        if (exp % 2 == 1)
            result = product(result, a);

        return result;
    }
}

int main(void) {
    ll n, b;
    cin >> n >> b;

    Matrix ans(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> ans.arr[i][j];

    ans = power(ans, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans.arr[i][j] % MOD << ' ';
        cout << '\n';
    }

    return 0;
}
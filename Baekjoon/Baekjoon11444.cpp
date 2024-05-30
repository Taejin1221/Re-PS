// Baekjoon11444.cpp
#include <iostream>

#define MOD 1'000'000'007LL

using namespace std;

using ll = long long;

struct Matrix {
    ll a, b, c, d;
    Matrix(): a(1), b(1), c(1), d(0) { }

    Matrix operator*(const Matrix& mat2) {
        Matrix result;

        result.a = a * mat2.a + b * mat2.c;
        result.b = a * mat2.b + b * mat2.d;
        result.c = c * mat2.a + d * mat2.c;
        result.d = c * mat2.b + d * mat2.d;

        return result;
    }

    Matrix operator%(const ll mod) {
        Matrix result = *this;
        result.a %= mod;
        result.b %= mod;
        result.c %= mod;
        result.d %= mod;

        return result;
    }
};

Matrix matPow(Matrix mat, ll exp) {
    if (exp <= 1)
        return mat % MOD;
    else {
        Matrix half = matPow(mat, exp / 2);

        Matrix result = (half * half) % MOD;
        if (exp % 2 == 1)
            result = (result * Matrix()) % MOD;

        return result;
    }
}

int main(void) {
    ll n;
    cin >> n;

    Matrix fibMat = matPow(Matrix(), n - 1);

    cout << fibMat.a << '\n';

    return 0;
}
// Baekjoon32748.cpp
#include <iostream>

using namespace std;

int getFrom(int func, int arr[]) {
    int a = 0, digit1 = 0;
    while (func) {
        a *= 10;
        a += arr[func % 10];

        func /= 10;
        digit1++;
    }

    int result = 0, digit2 = 0;
    while (a) {
        result *= 10;
        result += a % 10;

        a /= 10;
        digit2++;
    }

    for (int i = 0; i < (digit1 - digit2); i++)
        result *= 10;

    return result;
}

int main(void) {
    int f[10], f_1[10];
    for (int i = 0; i <= 9; i++) {
        int temp;
        cin >> temp;

        f[i] = temp;
        f_1[temp] = i;
    }

    int fa, fb;
    cin >> fa >> fb;
    int a = getFrom(fa, f_1), b = getFrom(fb, f_1);
    
    cout << getFrom(a + b, f) << '\n';
    
    return 0;
}
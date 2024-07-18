// Baekjoon20548.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ll c;
    cin >> c;

    int arr[20] = { 1, };
    ll curr = 1, step = 1;
    while (curr != c) {
        arr[0]++;

        int carry = arr[0] / 3;
        arr[0] %= 3;
        for (int i = 1; carry != 0; i++) {
            arr[i] += carry;
            carry = arr[i] / 3;
            arr[i] %= 3;
        }

        curr = 0;
        ll pow7 = 1;
        for (int i = 0; i < 20; i++) {
            curr += pow7 * arr[i];
            pow7 *= 7;
        }
        step++;
    }

    cout << step << '\n';

    return 0;
}
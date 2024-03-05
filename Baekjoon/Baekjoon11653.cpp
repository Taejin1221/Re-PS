// Baekjoon11653.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        while (n != 0 && n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }

    return 0;
}
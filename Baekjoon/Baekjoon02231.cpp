// Baekjoon02231.cpp
#include <iostream>

using namespace std;

int sumDigit(int n) {
    int result = 0;
    while (n) {
        result += n % 10;
        n /= 10;
    }

    return result;
}

int main(void) {
    int n;
    cin >> n;

    int generator = 0;
    for (int i = 0; i < n; i++) {
        if (n == (i + sumDigit(i))) {
            generator = i;
            break;
        }
    }

    cout << generator << '\n';

    return 0;
}
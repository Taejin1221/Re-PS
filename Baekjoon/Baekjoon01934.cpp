// Baekjoon01934.cpp
#include <iostream>

using namespace std;

int getGCD(int a, int b) {
    return (a % b == 0) ? b : getGCD(b, a % b);
}

/* int getLCM(int a, int b) {
    int result;
    for (int i = 1; i <= b; i++) {
        result = a * i;

        if (result % b == 0)
            break;
    }

    return result;
} */

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;

        int gcd = (a > b) ? getGCD(a, b) : getGCD(b, a);
        cout << a * b / gcd << '\n';

        // cout << getLCM(a, b) << '\n';
    }

    return 0;
}
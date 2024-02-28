// Baekjoon03052.cpp
#include <iostream>

using namespace std;

int main(void) {
    bool remainders[42] = { false, };

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;

        int remain = num % 42;
        if (!remainders[remain]) {
            remainders[remain] = true;
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
// Baekjoon02200.cpp
#include <iostream>

using namespace std;

int getDigit(int n) {
    int result = 0;
    while (n) {
        result++;
        n /= 10;
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int co;
    cin >> co; // 첫항은 반드시 1

    int ans = -1; // 처음에 * x를 지워주기 위함
    for (int i = 1; i <= n; i++) {
        cin >> co;

        ans += 2; // * x
        if (co != 0)
            ans += getDigit(co) + 1; // + a
    }
    ans++;

    cout << ans << '\n';

    return 0;
}
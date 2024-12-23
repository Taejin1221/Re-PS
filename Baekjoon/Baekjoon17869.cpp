// Baekjoon17869.cpp
#include <iostream>

using namespace std;

int main(void) {
    long long n;
    cin >> n;

    int ans = 0;
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n++;
        ans++;
    }

    cout << ans << '\n';
}

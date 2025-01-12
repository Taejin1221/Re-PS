// Baekjoon21869.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << '\n';
        cout << "1 1\n";

        return 0;
    }

    cout << (n + (n - 2)) << '\n';
    for (int i = 1; i <= n; i++)
        cout << i << " 1\n";
    for (int i = 2; i <= n - 1; i++)
        cout << i << ' ' << n << '\n';

    return 0;
}

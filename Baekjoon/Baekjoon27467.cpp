// Baekjoon27467.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int p = 0, q = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a % 3 == 0)
            q++;
        else if (a % 3 == 1)
            p++;
        else if (a % 3 == 2)
            p--, q--;
    }

    cout << p << ' ' << q << '\n';

    return 0;
}
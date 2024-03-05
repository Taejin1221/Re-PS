// Baekjoon02581.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

bool isPrime(int n) {
    if (n == 1)
        return false;
    else {
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;

    pii ans = { m, 0 };
    for (int i = n; i <= m; i++) {
        if (isPrime(i)) {
            ans.first = min(ans.first, i);
            ans.second += i;
        }
    }

    if (ans.second == 0)
        cout << -1;
    else
        cout << ans.second << '\n' << ans.first;
    cout << '\n';

    return 0;
}
#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0)
            sum += i;
    }

    if (sum == n)
        cout << "Perfect";
    else if (sum < n)
        cout << "Deficient";
    else
        cout << "Abundant";
    cout << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

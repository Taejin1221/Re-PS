#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int step = k * (k + 1) / 2;
    if (step > n)
        cout << -1;
    else {
        int diff = n - step;
        if (diff % k == 0)
            cout << (k - 1);
        else
            cout << k;
    }
    cout << '\n';

    return 0;
}

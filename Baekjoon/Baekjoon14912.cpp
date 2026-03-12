#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int digit[10] = { 0, };
    for (int i = 1; i <= n; i++) {
        int d = i;
        while (d) {
            digit[d % 10]++;
            d /= 10;
        }
    }

    cout << digit[m] << '\n';

    return 0;
}

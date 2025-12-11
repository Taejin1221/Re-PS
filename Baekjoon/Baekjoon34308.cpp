#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, n;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        cout << (((k - 1) > (m - k)) ? m : 1) << ' ';
    }
    cout << '\n';

    return 0;
}

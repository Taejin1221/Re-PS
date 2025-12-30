#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, t;
    cin >> a >> t;

    cout << (max(0, 10 + 2 * (25 - a + t))) << '\n';

    return 0;
}

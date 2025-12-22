#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k, n;
    cin >> k >> n;

    cout << (n + 1) << ' ' << (k * n + 1) << '\n';

    return 0;
}

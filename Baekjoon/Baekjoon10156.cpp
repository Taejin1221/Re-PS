#include <iostream>

using namespace std;

int main() {
    int k, n, m;
    cin >> k >> n >> m;

    cout << max(0, (n * k) - m) << '\n';

    return 0;
}

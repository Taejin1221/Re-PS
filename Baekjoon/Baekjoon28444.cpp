#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, i, a, r, c;
    cin >> h >> i >> a >> r >> c;

    cout << ((h * i) - (a * r * c)) << '\n';

    return 0;
}

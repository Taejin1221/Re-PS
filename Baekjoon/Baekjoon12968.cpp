#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int r, c, k;
    cin >> r >> c >> k;

    if (k == 1 || (r % 2 == 0 || c % 2 == 0))
        cout << 1;
    else
        cout << 0;
    cout << '\n';

    return 0;
}

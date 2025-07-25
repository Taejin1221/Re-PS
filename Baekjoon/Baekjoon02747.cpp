#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int f1 = 0, f2 = 1;
    for (int i = 2; i <= n; i++) {
        int f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }

    cout << f2 << '\n';

    return 0;
}

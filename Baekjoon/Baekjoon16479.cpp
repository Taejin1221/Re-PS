#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double k, d1, d2;
    cin >> k >> d1 >> d2;

    double base = (d1 - d2) / 2.0;

    cout << fixed;
    cout.precision(6);

    cout << k * k - base * base << '\n';
    
    return 0;
}

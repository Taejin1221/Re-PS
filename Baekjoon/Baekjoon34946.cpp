#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((a + b <= d) && (c <= d))
        cout << "~.~";
    else if (a + b <= d)
        cout << "Shuttle";
    else if (c <= d)
        cout << "Walk";
    else
        cout << "T.T";
    cout << '\n';

    return 0;
}

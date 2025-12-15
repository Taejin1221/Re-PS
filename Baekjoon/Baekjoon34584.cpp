#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, d;
    cin >> x >> d;

    if (x * 2 <= d)
        cout << "double it";
    else
        cout << "take it";
    cout << '\n';

    return 0;
}

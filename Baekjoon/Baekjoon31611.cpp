#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if (n % 7 == 2)
        cout << 1;
    else
        cout << 0;
    cout << '\n';

    return 0;
}

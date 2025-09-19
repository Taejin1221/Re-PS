#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    cout << "Gnomes:\n";
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if ((a < b && b < c) || (a > b && b > c))
            cout << "Ordered";
        else
            cout << "Unordered";
        cout << '\n';
    }

    return 0;
}

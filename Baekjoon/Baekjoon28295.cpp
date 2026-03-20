#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        int t;
        cin >> t;

        if (t == 1)
            ans = (ans + 1) % 4;
        else if (t == 2)
            ans = (ans + 2) % 4;
        else
            ans = (ans - 1 + 4) % 4;
    }

    if (ans == 0)
        cout << 'N';
    else if (ans == 1)
        cout << 'E';
    else if (ans == 2)
        cout << 'S';
    else
        cout << 'W';
    cout << '\n';

    return 0;
}

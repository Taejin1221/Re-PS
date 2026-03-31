#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int r, e, c;
        cin >> r >> e >> c;

        int ad = e - c;

        if (r > ad)
            cout << "do not advertise";
        else if (r < ad)
            cout << "advertise";
        else
            cout << "does not matter";
        cout << '\n';
    }

    return 0;
}

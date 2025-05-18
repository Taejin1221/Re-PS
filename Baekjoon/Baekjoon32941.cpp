#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, x;
    cin >> t >> x;

    int n;
    cin >> n;

    bool ans = true;
    while (n--) {
        int m;
        cin >> m;

        bool result = false;
        while (m--) {
            int temp;
            cin >> temp;

            if (temp == x)
                result = true;
        }

        if (!result)
            ans = false;
    }

    cout << (ans ? "YES" : "NO") << '\n';
    
    return 0;
}

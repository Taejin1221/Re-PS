#include <iostream>

#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    string seat;
    cin >> seat;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans++;
        if (seat[i] == 'L')
            i++;
    }

    cout << min(ans + 1, n) << '\n';

    return 0;
}

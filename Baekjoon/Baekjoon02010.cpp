#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        ans += temp;
    }

    cout << ans - (n - 1) << '\n';
    
    return 0;
}

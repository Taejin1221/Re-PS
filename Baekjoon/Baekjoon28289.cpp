#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int p;
    cin >> p;

    int ans[4] = { 0, };
    for (int i = 0; i < p; i++) {
        int g, c, n;
        cin >> g >> c >> n;

        if (g == 1)
           ans[3]++;
        else if (c <= 2)
            ans[0]++;
        else if (c == 3)
            ans[1]++;
        else
            ans[2]++;
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';

    return 0;
}

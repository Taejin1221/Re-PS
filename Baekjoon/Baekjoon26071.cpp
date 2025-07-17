// Baekjoon26071.cpp
#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> gomgom;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char g;
            cin >> g;
            if (g == 'G')
                gomgom.push_back({ i, j });
        }
    }

    int ans = 0x3f3f3f3f;
    if (gomgom.size() == 1)
        ans = 0;
    else {
        for (int i = 0; i < 4; i++) {
            int left = 0;
            for (pii& gom : gomgom)
                left = max(left, gom.second);

            bool clear = true;
            int base = gomgom[0].first;
            for (pii& gom : gomgom) {
                if (base != gom.first) {
                    clear = false;
                    break;
                }
            }

            if (clear)
                ans = min(ans, left);
            else {
                int up = 0, down = 0;
                for (pii& gom : gomgom) {
                    up = max(up, gom.first);
                    down = max(down, (n - gom.first - 1));
                }

                ans = min(ans, min(left + up, left + down));
            }

            for (pii& gom : gomgom) {
                int temp = gom.first;
                gom.first = n - (gom.second + 1);
                gom.second = temp;
            }

        }
    }

    cout << ans << '\n';

    return 0;
}

#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pii> ans;
    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= 200; j++) {
            if ((i * 508 + j * 212) * 4763 == n
                || (i * 508 + j * 305) * 4763 == n
                || (i * 108 + j * 212) * 4763 == n
                || (i * 108 + j * 305) * 4763 == n
            )
                ans.push_back({ i, j });
        }
    }

    cout << ans.size() << '\n';
    for (pii& a : ans)
        cout << a.first << ' ' << a.second << '\n';
    
    return 0;
}

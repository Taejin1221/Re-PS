#include <iostream>

#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    pair<string, int> ans = { "", 0 };
    for (int i = 0; i < n; i++) {
        string str;
        int y;

        cin >> str >> y;

        if (y == 2026)
            ans = { str, y };
    }

    cout << ans.first << '\n';

    return 0;
}

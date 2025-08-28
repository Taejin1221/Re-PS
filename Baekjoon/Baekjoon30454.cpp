#include <iostream>

#include <string>

using namespace std;

using pii = pair<int, int>;

int main() {
    int n, l;
    cin >> n >> l;

    pii ans = { 0, 0 };
    for (int t = 0; t < n; t++) {
        string str;
        cin >> str;

        int black = 0;
        for (int i = 0; i < l; i++) {
            if (str[i] == '1') {
                black++;
                while (i < l && str[i] == '1')
                    i++;
            }
        }

        if (ans.first < black)
            ans = { black, 1 };
        else if (ans.first == black)
            ans.second++;
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}

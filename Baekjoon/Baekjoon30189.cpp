#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int c = 0; c <= (n + m); c++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (i + j == c)
                    ans++;
    cout << ans << '\n';

    return 0;
}

// Baekjoon16439.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int chicken[30][30];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> chicken[i][j];

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                int result = 0;
                for (int l = 0; l < n; l++)
                    result += max(chicken[l][i], max(chicken[l][j], chicken[l][k]));
                ans = max(ans, result);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
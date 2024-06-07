// Baekjoon11660.cpp
#include <iostream>

#include <vector>

using namespace std;

using ll = long long;

ll getPrefixSum(vector<vector<ll>>& prefix, int x1, int y1, int x2, int y2) {
    return prefix[x2 + 1][y2 + 1] - prefix[x1][y2 + 1] - prefix[x2 + 1][y1] + prefix[x1][y1];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> prefix(n + 1, vector<ll> (n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int curr;
            cin >> curr;

            prefix[i + 1][j + 1] = prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + curr;
        }
    }

    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << getPrefixSum(prefix, x1 - 1, y1 - 1, x2 - 1, y2 - 1) << '\n';
    }

    return 0;
}
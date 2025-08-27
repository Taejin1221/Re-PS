#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int arr[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[j][i];
        }
    }

    pii ans;
    int sum[100] = { 0, };
    for (int i = 0; i < m; i++) {
        bool end = false;
        for (int j = 0; j < n; j++) {
            sum[j] += arr[i][j];
            if (sum[j] >= k) {
                ans = { j + 1, i + 1};
                end = true;
                break;
            }
        }

        if (end)
            break;
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}

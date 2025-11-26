#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int arr[1'000][1'000];
    for (int i = 0; i < m; i++)
        arr[0][i] = i + 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = arr[i - 1][j] + 1;
        }
    }

    if (k >= arr[n - 1][m - 1]) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << arr[i][j] << ' ';
            cout << '\n';
        }
    } else
        cout << "NO\n";

    return 0;
}

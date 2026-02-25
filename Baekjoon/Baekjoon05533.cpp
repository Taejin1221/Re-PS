#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int arr[3][200];
    for (int i = 0; i < n; i++) {
        cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
    }

    int ans[200] = { 0, };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            bool win = true;
            for (int k = 0; k < n; k++) {
                if (j != k && arr[i][j] == arr[i][k]) {
                    win = false;
                    break;
                }
            }

            if (win)
                ans[j] += arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';

    return 0;
}

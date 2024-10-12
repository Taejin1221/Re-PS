// Baekjoon28456.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int m;
    cin >> m;

    while (m--) {
        int opr;
        cin >> opr;

        if (opr == 1) {
            int row;
            cin >> row;
            row--;

            int last = arr[row][n - 1];
            for (int i = n - 1; i > 0; i--)
                arr[row][i] = arr[row][i - 1];
            arr[row][0] = last;
        } else {
            int copy[100][100];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    copy[j][n - i - 1] = arr[i][j];

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    arr[i][j] = copy[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
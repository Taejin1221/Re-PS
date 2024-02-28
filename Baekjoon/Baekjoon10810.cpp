// Baekjoon10810.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    int arr[101] = { 0, };
    for (int t = 0; t < m; t++) {
        int i, j, k;
        cin >> i >> j >> k;

        for (int l = i; l <= j; l++) {
            arr[l] = k;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}
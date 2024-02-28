// Baekjoon10813.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    int bucket[101];
    for (int i = 1; i <= n; i++)
        bucket[i] = i;

    for (int t = 0; t < m; t++) {
        int buck1, buck2;
        cin >> buck1 >> buck2;

        int temp = bucket[buck1];
        bucket[buck1] = bucket[buck2];
        bucket[buck2] = temp;
    }

    for (int i = 1; i <= n; i++)
        cout << bucket[i] << ' ';
    cout << '\n';

    return 0;
}